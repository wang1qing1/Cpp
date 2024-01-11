.PHONY:all
all:client server
client:client.cc
	g++ -o $@ $^ -std=c++11 -lpthread	
server:server.cc
	g++ -o $@ $^ -std=c++11 -lpthread
.PHONY:clean
clean:
	rm -rf server client
