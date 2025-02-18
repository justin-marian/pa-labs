PROJECT_bfs=bfs
PROJECT_dfs=dfs

SOURCES_bfs=../bfs.c ../lib/stack.c ../lib/queue.c ../lib/graph.c
SOURCES_dfs=../dfs.c ../lib/stack.c ../lib/queue.c ../lib/graph.c

LIBRARY=nope
INCPATHS=../include

LIBPATHS=.
LDFLAGS=

CFLAGS=-c -Wall -Werror -Wno-error=unused-variable
CC=gcc

INCFLAGS=$(foreach TMP, $(INCPATHS), -I$(TMP))
LIBFLAGS=$(foreach TMP, $(LIBPATHS), -L$(TMP))

# Automatic generation BFS / DFS
OBJECTS_bfs=$(SOURCES_bfs:.c=.o)
OBJECTS_dfs=$(SOURCES_dfs:.c=.o)

# Set up the output file names 
# for the different output types
#		BFS   /   DFS
BINARY_bfs=$(PROJECT_bfs)
BINARY_dfs=$(PROJECT_dfs)

all: bfs dfs

bfs: $(OBJECTS_bfs)
	$(CC) $(LIBFLAGS) $(OBJECTS_bfs) $(LDFLAGS) -o $(BINARY_bfs)

dfs: $(OBJECTS_dfs)
	$(CC) $(LIBFLAGS) $(OBJECTS_dfs) $(LDFLAGS) -o $(BINARY_dfs)

.c.o:
	$(CC) $(INCFLAGS) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o ../$(BINARY_bfs) ../$(BINARY_dfs) ../lib/*.o ../*.o bfs dfs
