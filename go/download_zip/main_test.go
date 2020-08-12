package main
import "testing"

func TestGithubAction( t *testing.T ){
	t.Log("test github action")
}

func TestHttpData( t *testing.T ){
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


func TestHttpError( t *testing.T ){
	t.Error("test http error")
}