package main

import (
	"fmt"
	"os"
	"io"
)

func main() {
	var num, tmp, del2 int32
	file, err := os.Open("input.txt")
	defer file.Close()
	if err != nil{
		return
	}
	file1, err1 := os.Create("output.txt")
	defer file1.Close()
	if err1 != nil{
		return
	}
	_, err4 := fmt.Fscanf(file, "%d\n", &num)
	if (err4 == io.EOF) {
		fmt.Fprintf(file1, "%d\n", 0)
		return
	}
	if (num == 1) {
		fmt.Fprintf(file1, "%d\n", 0)
		return
	}
	m := make(map[int32]int8)
	i := 0
	for (true) {
		_, err2 := fmt.Fscanf(file, "%d", &tmp)
		if (err2 == io.EOF) {
			break
		}
		i++
		if (i > 100000) {
			fmt.Fprintf(file1, "%d\n", 0)
			return	
		}
		if (tmp < num) {
			if _, inMap := m[tmp]; !inMap {
				m[tmp] = 0
			}
			if (num / 2 == tmp && num % 2 == 0) {
				del2++
				if (del2 >= 2) {
					fmt.Fprintf(file1, "%d\n", 1)
					return
				}
			}
			if (num-tmp != tmp) {
				if _, inMap := m[num-tmp]; inMap {
					fmt.Fprintf(file1, "%d\n", 1)
					return
				}
			}
		}
	}
	fmt.Fprintf(file1, "%d\n", 0)
}
