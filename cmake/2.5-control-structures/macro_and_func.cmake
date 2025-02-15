# usage list_print caption [list]
function(list_print) 
    message("\n\tEnter function...")
    set(output)
    list(POP_FRONT ARGV caption)
    foreach(VAR IN LISTS ARGV)
        list(GET ARGV -1 last) # value of last so only works in this example rather than in general (we need to workout indexing)
        if(NOT ${VAR} EQUAL last)
            list(APPEND output ${VAR},\  )
        else()
            list(APPEND output ${VAR})
        endif()
    endforeach()
    message("\n\t\t" ${caption} ${output})
    message("\n\tExit Function...")
endfunction()


set(lst2 1 2 3 4 5 6)
message("global...")
list_print("Initial list defined in global scope is " ${lst2})
macro(sort_5_or_greater_and_print)
    message("\nEnter macro...")
    list(LENGTH lst2 COUNT)
    while(COUNT)
        list(POP_BACK lst2 CURRENT)
        if(CURRENT GREATER_EQUAL 5)
            list(PREPEND matched ${CURRENT}) 
        else()
            list(PREPEND unmatched ${CURRENT})
        endif()
        list(LENGTH lst2 COUNT)
    endwhile()
    list_print("Matched were " ${matched})
    list_print("Unmatched were " ${unmatched})
    message("\n\tvalue of caption used in function is [" ${caption} "] showing function has local scope")
    message("\nExit macro...")
endmacro()

sort_5_or_greater_and_print()

list(LENGTH lst2 END_SIZE)
message("\nIn global scope the size of list is [" ${END_SIZE} "] showing macro is in global scope\n" )
