package main

import (
	"encoding/json"
	"fmt"
	"io"
	"io/ioutil"
	"os"
	"strings"
	"strconv"
)

type Persons struct {
	Name	interface{} `json:"name"`
	Email	interface{} `json:"email"`
}

type Browsers struct {
	Brows	[]string `json:"browsers"`
}

const filePath1 string = "./data/users.txt"

func FastSearch(out io.Writer) {
	file, err := os.Open(filePath1)
	if err != nil {
		panic(err)
	}

	fileContents, err := ioutil.ReadAll(file)
	if err != nil {
		panic(err)
	}

	fmt.Fprintln(out, "found users:")


	seenBrowsers := make(map[string]int, 200)

	lines := strings.Split(string(fileContents), "\n")

	isAndroid, isMSIE := false, false
	pers := &Persons{}
	for i, line := range lines {
		if (strings.Contains(line, "Android") || strings.Contains(line, "MSIE")) {
			tmpBrows := &Browsers{}
			err := json.Unmarshal([]byte(line), &tmpBrows)
			if err != nil {
				panic(err)
			}
			for i := range tmpBrows.Brows {
				if (strings.Contains(tmpBrows.Brows[i], "Android")) {
					isAndroid = true
					_, ok := seenBrowsers[tmpBrows.Brows[i]]
					if !ok {
						seenBrowsers[tmpBrows.Brows[i]] = 1
					}
				}
				if (strings.Contains(tmpBrows.Brows[i], "MSIE")) {
					isMSIE = true
					_, ok := seenBrowsers[tmpBrows.Brows[i]]
					if !ok {
						seenBrowsers[tmpBrows.Brows[i]] = 1
					}
				}
			}
		}
		if !(isAndroid && isMSIE) {
			isAndroid = false
			isMSIE = false
			continue
		}
		err := json.Unmarshal([]byte(line), &pers)
		if err != nil {
			panic(err)
		}
		mail := strings.Split(pers.Email.(string), "@")
		fmt.Fprintln(out, "[" + strconv.Itoa(i) + "]", pers.Name, "<" + mail[0], "[at]", mail[1]  + ">")
		isAndroid = false
		isMSIE = false
	}
	fmt.Fprintln(out, "\nTotal unique browsers", len(seenBrowsers))
}

func main() {
	FastSearch(os.Stdout)
}