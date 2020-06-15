package main

import (
	"fmt"
	"strconv"
	"sync"
	"sort"
)

func MultiHash(sec chan string, forSort *[]string, wg *sync.WaitGroup, l int) {
	defer wg.Done()
	wg_sing := &sync.WaitGroup{}
	for i := 0; i < l; i++ {
		wg_sing.Add(1)
		go func(data string, forSort *[]string, i int) {
			defer wg_sing.Done()
			ar := make([]string, 6, 6)
			bl := make([]bool, 6, 6)
			for j := 0; j < 6; j++ {
				go func (ar []string, bl []bool, j int, data string) {
					ar[j] = DataSignerCrc32(strconv.Itoa(j) + data)
					bl[j] = true
				}(ar, bl, j, data)
			}
			k := 0
			for k < 6 {
				if bl[k] == true {
					(*forSort)[i] += ar[k]
					k++
				}
			}
		}((<- sec), forSort, i)
	}
	wg_sing.Wait()
	close(sec)
}

func SingleHash(ch chan string, sec chan string, wg *sync.WaitGroup, mu *sync.Mutex, l int) {
	defer wg.Done()
	wg_sing := &sync.WaitGroup{}
	for i := 0; i < l; i++ {
		wg_sing.Add(1)
		go func(sec chan string, data string, wg_sing *sync.WaitGroup) {
			defer wg_sing.Done()
			s1, s2 := "", ""
			wg_s := &sync.WaitGroup{}
			wg_s.Add(1)
			go func(s1 *string, data string) {
				defer wg_s.Done()
				*s1 = DataSignerCrc32(data) + "~"
			}(&s1, data)
			mu.Lock()
			s := DataSignerMd5(data)
			mu.Unlock()
			wg_s.Add(1)
			go func(s2 *string, data string) {
				defer wg_s.Done()
				*s2 = DataSignerCrc32(s)
			}(&s2, data)
			wg_s.Wait()
			sec <- s1 + s2

		}(sec, (<- ch), wg_sing)
	}
	wg_sing.Wait()
	close(ch)
}

func ExecutePipeline(nums ...interface{}) {
	mu := &sync.Mutex{}
	wg := &sync.WaitGroup{}
	ch := make(chan string, len(nums))
	sec := make(chan string, len(nums))
	forSort := make([]string, len(nums))
	l := len(nums)
	go func(ch chan string, l int) {
		for i := 0; i < l; i++ {
			data, ok := nums[i].(string)
			if !ok {
				continue
			}
			ch <- data
		}
	}(ch, l)
	wg.Add(1)
	go SingleHash(ch, sec, wg, mu, l)
	wg.Add(1)
	go MultiHash(sec, &forSort, wg, l)
	wg.Wait()
	res := CombineResults(forSort)
	fmt.Println(res)
}

func CombineResults(forSort []string) string {
	sort.Strings(forSort)
	res := forSort[0]
	for i := 1; i < len(forSort); i++ {
		res += "_" + forSort[i]
	}
	return res
}

func main() {
	ch := []interface{}{"0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9","0","1", "2", "3", "4", "5", "6", "7", "8", "9"}
	ExecutePipeline(ch...)
}
