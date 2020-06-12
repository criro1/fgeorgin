package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a, b string
	var tmp, one int
	var x, y, res []int
	fmt.Scan(&a)
	fmt.Scan(&b)
	for i := len(a) - 1; i >= 0; i-- {
		tmp, _ = strconv.Atoi(string(a[i]))
		x = append(x, tmp)
	}
	for i := len(b) - 1; i >= 0; i-- {
		tmp, _ = strconv.Atoi(string(b[i]))
		y = append(y, tmp)
	}
	if (len(x) < len(y)) {
		x,y = y, x
	}
	for i := range y {
		tmp = x[i] + y[i] + one
		if (tmp >= 10) {
			one = 1
		} else {
			one = 0
		}
		res = append(res, tmp % 10)
	}
	if (len(x) > len(y)) {
		for i:= len(y); i < len(x); i++ {
			if i >= len(y) {
				res = append(res, (x[i] + one) % 10)
				if (x[i] + one >= 10) {
					one = 1
				} else {
					one = 0
				}
			} else {
				res = append(res, x[i])
			}
		}
	}
	if (one == 1) {
		res = append(res, 1)
	}
	for i := len(res) - 1; i >= 0; i-- {
		fmt.Print(res[i])
	}
	fmt.Println()
}