# 編譯目標程式
main.out:main.cpp	map.o	bfs.o	dfs.o
	g++	main.cpp	map.o	bfs.o	dfs.o	-o	main.out

#編譯相關程式
map.o:map.cpp
	g++	-c	map.cpp

bfs.o:bfs.cpp
	g++	-c	bfs.cpp

dfs.o:dfs.cpp
	g++	-c	dfs.cpp

#執行程式
run:main.out
	./main.out

#刪除程式
clean:
	rm	-f	map.o	bfs.o	dfs.o	main.out