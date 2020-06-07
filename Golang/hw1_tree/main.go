package main

import (
	"fmt"
	"io"
	"os"
	"io/ioutil"
)

func printing(output io.Writer, file os.FileInfo, num int, tabs string, last int) {
	if file.IsDir() == true {
		if num == last {
			fmt.Fprint(output, tabs, "└───", file.Name(), "\n")
		} else {
			fmt.Fprint(output, tabs, "├───", file.Name(), "\n")
		}
	} else {
		if file.Size() == 0 {
			if num == last {
				fmt.Fprint(output, tabs, "└───", file.Name(), " (empty)", "\n")
			} else {
				fmt.Fprint(output, tabs, "├───", file.Name(), " (empty)", "\n")
			}
		} else {
			if num == last {
				fmt.Fprint(output, tabs, "└───", file.Name(), " (", file.Size(), "b)", "\n")
			} else {
				fmt.Fprint(output, tabs, "├───", file.Name(), " (", file.Size(), "b)", "\n")
			}
		}
	}
}

func ftPrint(output io.Writer, currDir string, printFiles bool, level int, pipes []int) error {
	files, err := ioutil.ReadDir(currDir)
	if err != nil {
		return fmt.Errorf("Problems with directory")
	}
	var tabs, last = "", len(files) - 1
	for i := 0; i < level; i++ {
		if pipes[i] == 0 {
			tabs += "│"
		}
		tabs += "\t"
	}
	if printFiles == false {
		for num, _ := range files {
			if !files[num].IsDir() {
				continue
			}
			last = num
		}
	}
	for num, file := range files {
		if printFiles == false && !file.IsDir() {
			continue
		}
		if num == last {
			pipes[level] = 1
		}
		cp := make([]int, level + 2, level + 2)
		copy(cp, pipes[:level + 1])
		printing(output, file, num, tabs, last)
		ftPrint(output, currDir + "/" + file.Name(), printFiles, level + 1, cp)
	}
	return nil
}

func dirTree(output io.Writer, path string, printFiles bool) error {
	return ftPrint(output, path, printFiles, 0, make([]int, 1, 1))
}

func main() {
	out := os.Stdout
	if !(len(os.Args) == 2 || len(os.Args) == 3) {
		panic("usage go run main.go . [-f]")
	}
	path := os.Args[1]
	printFiles := len(os.Args) == 3 && os.Args[2] == "-f"
	err := dirTree(out, path, printFiles)
	if err != nil {
		panic(err.Error())
	}
}
