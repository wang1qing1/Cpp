
aux_source_directory(./ SRC)

include_directories(${headpath})

set(LIBRARY_OUTPUT_PATH ${libpath})

add_library(sort STATIC ${SRC})

