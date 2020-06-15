package main

import (
	"fmt"
	"strconv"
	"sync"
	"strings"
	"sort"
)

func CombineResults(in chan interface{}, out chan interface{}) {
	var forSort []string
	for el := range(in) {
		forSort = append(forSort, el.(string))
	}
	sort.Strings(forSort)
	out <- strings.Join(forSort, "_")
}

func MultiHash(in chan interface{}, out chan interface{}) {
	wg := &sync.WaitGroup{}
	for str := range(in) {
		wg.Add(1)
		go func(str interface{}, out chan interface{}, wg *sync.WaitGroup) {
			defer wg.Done()
			data := (str).(string)
			ar := make([]string, 6, 6)
			wg_6 := &sync.WaitGroup{}
			for j := 0; j < 6; j++ {
				wg_6.Add(1)
				go func (ar []string, j int, data string) {
					defer wg_6.Done()
					ar[j] = DataSignerCrc32(strconv.Itoa(j) + data)
				}(ar, j, data)
			}
			wg_6.Wait()
			out <- strings.Join(ar, "")
		}(str, out, wg)
	}
	wg.Wait()
}

func SingleHash(in chan interface{}, out chan interface{}) {
	mu := &sync.Mutex{}
	wg_sing := &sync.WaitGroup{}
	for el := range(in) {
		wg_sing.Add(1)
		go func(el interface{}, wg_sing *sync.WaitGroup, out chan interface{}) {
			defer wg_sing.Done()
			data := ""
			switch v := el.(type) {
			case int:
				data = strconv.Itoa(v)
			case string:
				data = v
			default:
				fmt.Printf("I don't know about type %T!\n", v)
			}
			s1, s2 := "", ""
			wg_s := &sync.WaitGroup{}
			wg_s.Add(1)
			go func(s2 *string, data string, mu *sync.Mutex) {
				defer wg_s.Done()
				mu.Lock()
				s := DataSignerMd5(data)
				mu.Unlock()
				*s2 = DataSignerCrc32(s)
			}(&s2, data, mu)
			wg_s.Add(1)
			go func(s1 *string, data string) {
				defer wg_s.Done()
				*s1 = DataSignerCrc32(data) + "~"
			}(&s1, data)
			wg_s.Wait()
			out <- s1 + s2
		}(el, wg_sing, out)
	}
	wg_sing.Wait()
}


func ExecutePipeline(workers ...job) {
	in := make(chan interface{}, 100)
	wg := &sync.WaitGroup{}
	for i := range(workers) {
		wg.Add(1)
		out := make(chan interface{}, 100)
		go func(wg *sync.WaitGroup, worker_i job, in chan interface{}, out chan interface{}) {
			defer wg.Done()
			worker_i(in, out)
			close(out)
		}(wg, workers[i], in, out)
		in = out
	}
	wg.Wait()
}
