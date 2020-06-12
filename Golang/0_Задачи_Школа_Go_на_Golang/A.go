package main

import (
	"fmt"
	"io"
)

func main() {
	var num int
	m := make(map[int]int)
	for (true) {
		_, err := fmt.Scan(&num)
		if (err != nil || err == io.EOF) {
			break
		}
		if _, inMap := m[num]; inMap {
			m[num]++
		} else {
			m[num] = 1
		}
	}
	for key, value := range m {
		if (value == 1) {
			fmt.Println(key)
		}
	}
}
