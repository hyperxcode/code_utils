package main
import(
	"testing"
	"io/ioutil"
	"fmt"
	"net/http"
	"io"
	"os"
	"bytes"
)
func TestGithubAction( t *testing.T ){
	t.Log("test github action")
}

func TestHttpFuncData( t *testing.T ){
	for i := 0; i < 10; i++ {
		res := initData(i, i)
		if res != i+i {
			t.Error("error initData function")
		}else{
			t.Log(res)
		}
	}
	t.Log("test function initData")
}

func CopyFile(byte []byte, dst string) (w int64, err error) {
	dstFile, err := os.Create(dst)
	if err != nil {
		fmt.Println(err.Error())
		return
	}
	defer dstFile.Close()
	return io.Copy(dstFile, bytes.NewReader(byte))
}

func TestHttp( t *testing.T ){
	res, err := http.Get("http://127.0.0.1:5678")
	if err != nil {
		t.Log("test http failed.")
		return
	}

	defer res.Body.Close()
	body, err := ioutil.ReadAll(res.Body)
	if err != nil {
		t.Log("test http err:"+ err.Error())
	}else if body != nil && len(body) > 0{
		CopyFile(body, "download.zip")
		t.Log("test http copy file")
	}else{
		t.Log("test http null")
	}
}

func TestHttpError( t *testing.T ){
	//t.Error("test http error")
}