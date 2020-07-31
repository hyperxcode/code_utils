package main

import (
	"archive/zip"
	"fmt"
	"io"
	"log"
	"net/http"
	"strconv"
)

func main() {
	http.HandleFunc("/zip", zipHandler)
	http.ListenAndServe(":5678", nil)
}

func zipHandler(rw http.ResponseWriter, r *http.Request) {
	zipName := "ZipTest.zip"
	//rw.Header().Set("Content-Type", "application/octet-stream")
	rw.Header().Set("Content-Type", "application/x-zip-compressed")
	//rw.Header().Set("Content-Type", "application/zip")
	rw.Header().Set("Content-Disposition", fmt.Sprintf("attachment; filename=\"%s\"", zipName))
	err := initZip(rw)
	if err != nil {
		log.Fatal(err)
	}
}

func initZip(w io.Writer) error {
	zipW := zip.NewWriter(w)
	defer zipW.Close()

	for i := 0; i < 10; i++ {
		f, err := zipW.Create(strconv.Itoa(i) + ".txt")
		if err != nil {
			return err
		}
		_, err = f.Write([]byte(fmt.Sprintf("Hello file %d", i)))
		if err != nil {
			return err
		}
	}
	return nil
}