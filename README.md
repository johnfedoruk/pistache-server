# Pistache Server
## Setup
Followed from [http://pistache.io/quickstart](http://pistache.io/quickstart)
```
git clone https://github.com/oktal/pistache.git
cd pistache
git submodule update --init
mkdir build
cd build
cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..
make
sudo make install

```

## Building Locally
```
git clone https://github.com/johnfedoruk/pistache-server.git
cd pistache-server
make
./run

```

## Accessing with cURL
```
curl localhost:8080 -H "auth-token:f8fe3bc90778c9eb1e3a80ac5ac4b7b71e50eeee13a887878dc6a683972aa0dd"

```

## More Information
[pistache.io](http://pistache.io/guide/)