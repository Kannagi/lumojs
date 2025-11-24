#!/bin/sh

#g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/main.cpp -o obj/src/main.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/allocator_eastl.cpp -o obj/src/eastl/allocator_eastl.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/assert.cpp -o obj/src/eastl/assert.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/atomic.cpp -o obj/src/eastl/atomic.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/fixed_pool.cpp -o obj/src/eastl/fixed_pool.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/hashtable.cpp -o obj/src/eastl/hashtable.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/intrusive_list.cpp -o obj/src/eastl/intrusive_list.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/numeric_limits.cpp -o obj/src/eastl/numeric_limits.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/red_black_tree.cpp -o obj/src/eastl/red_black_tree.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/string.cpp -o obj/src/eastl/string.o
g++  -O2 -Wno-language-extension-token -Wall -Wextra -Wno-strict-aliasing -Wno-unused-parameter  -Iinclude -c src/eastl/thread_support.cpp -o obj/src/eastl/thread_support.o

g++ -s   obj/src/main.o obj/src/eastl/allocator_eastl.o obj/src/eastl/assert.o obj/src/eastl/atomic.o obj/src/eastl/fixed_pool.o obj/src/eastl/hashtable.o obj/src/eastl/intrusive_list.o obj/src/eastl/numeric_limits.o obj/src/eastl/red_black_tree.o obj/src/eastl/string.o obj/src/eastl/thread_support.o  -o bin/demo 


