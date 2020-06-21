package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
	"github.com/mailru/easyjson/jlexer"
)

type Person struct {
	Name	string `json:"name"`
	Email	string `json:"email"`
	Brows	[]string `json:"browsers"`
}

const filePath1 string = "./data/users.txt"


func main() {
	FastSearch(os.Stdout)
}

func FastSearch(out io.Writer) {
	file, err := os.Open(filePath1)
	if err != nil {
		panic(err)
	}
	defer file.Close()

	fmt.Fprintln(out, "found users:")

	seenBrowsers := make(map[string]int, 120)
	isAndroid, isMSIE := false, false
	pers := &Person{}

	scanner := bufio.NewScanner(file)
	i := -1
	var line []byte
	for scanner.Scan() {
		i++
		line = scanner.Bytes()
		err := pers.UnmarshalJSON(line)
		if err != nil {
			panic(err)
		}
		for i := range pers.Brows {
			if (strings.Contains(pers.Brows[i], "Android")) {
				isAndroid = true
				_, ok := seenBrowsers[pers.Brows[i]]
				if !ok {
					seenBrowsers[pers.Brows[i]] = 1
				}
			}
			if (strings.Contains(pers.Brows[i], "MSIE")) {
				isMSIE = true
				_, ok := seenBrowsers[pers.Brows[i]]
				if !ok {
					seenBrowsers[pers.Brows[i]] = 1
				}
			}
		}
		if !(isAndroid && isMSIE) {
			isAndroid = false
			isMSIE = false
			continue
		}
		mail := strings.Split(pers.Email, "@")
		fmt.Fprintln(out, "[" + strconv.Itoa(i) + "] " + pers.Name + " <" + mail[0] +" [at] " + mail[1]  + ">")
		isAndroid = false
		isMSIE = false
	}
	fmt.Fprintln(out, "\nTotal unique browsers", len(seenBrowsers))
}

var (
	_ *jlexer.Lexer
)

func (v *Person) UnmarshalJSON(data []byte) error {
	r := jlexer.Lexer{Data: data}
	easyjson6e36b616DecodeHw3BenchMyPackage(&r, v)
	return r.Error()
}


func easyjson6e36b616DecodeHw3BenchMyPackage(in *jlexer.Lexer, out *Person) {
	isTopLevel := in.IsStart()
	if in.IsNull() {
		if isTopLevel {
			in.Consumed()
		}
		in.Skip()
		return
	}
	in.Delim('{')
	for !in.IsDelim('}') {
		key := in.UnsafeString()
		in.WantColon()
		if in.IsNull() {
			in.Skip()
			in.WantComma()
			continue
		}
		switch key {
		case "name":
			out.Name = string(in.String())
		case "email":
			out.Email = string(in.String())
		case "browsers":
			if in.IsNull() {
				in.Skip()
				out.Brows = nil
			} else {
				in.Delim('[')
				if out.Brows == nil {
					if !in.IsDelim(']') {
						out.Brows = make([]string, 0, 4)
					} else {
						out.Brows = []string{}
					}
				} else {
					out.Brows = (out.Brows)[:0]
				}
				for !in.IsDelim(']') {
					var v1 string
					v1 = string(in.String())
					out.Brows = append(out.Brows, v1)
					in.WantComma()
				}
				in.Delim(']')
			}
		default:
			in.SkipRecursive()
		}
		in.WantComma()
	}
	in.Delim('}')
	if isTopLevel {
		in.Consumed()
	}
}
