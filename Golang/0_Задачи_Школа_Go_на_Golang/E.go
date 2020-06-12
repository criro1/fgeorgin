package main

import (
	"fmt"
	"time"
    "math/rand"
)

func Merge2Channels(f func(int) int, in1 <-chan int, in2 <-chan int, out chan<- int, n int) {
	ar1 := make([]int, n * 2)
	bl1 := make([]bool, n * 2)
	go func() {
		for i := 0; i < n; i++ {
			go func(i int, ar1 []int, bl1 []bool) {
				go func(i int, x int) {
					ar1[i] = f(x)
					bl1[i] = true
				}(i, <- in1)
				go func(j int, y int) {
					ar1[j] = f(y)
					bl1[j] = true
				}(i + n, <- in2)
			}(i, ar1, bl1)
		}
	}()
	go func() {
		k := 0
		for (k < n) {
			for (bl1[k] && bl1[k + n]) {
				out <- ar1[k] + ar1[k + n]
				k++
			}
		}
	}()
}

func ft_f(num int) int {
	amt := time.Duration(rand.Intn(1500) + 1000)
	time.Sleep(time.Millisecond * amt)
	return (num * num)
}

func main() {
	var in1 chan int = make(chan int)
	var in2 chan int = make(chan int)
	var out chan int = make(chan int)

	go func() {
		var i int
		for i = 2; i < 21; i += 2 {
			in1 <- i
		}
	}()
	go func() {
		var i int
		for i = 3; i < 22; i += 2 {
			in2 <- i
		}
	}()
	Merge2Channels(ft_f, in1, in2, out, 7)
	for i := range out {
		fmt.Println(i)
		if (i == 313) {
			break
		}
	}
}
