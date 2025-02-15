
message("Just the list")
set(lst 1 2 3 4 5)
foreach(VAR IN LISTS lst )
    message(${VAR})
endforeach()

message("\nAdditional items")
foreach(VAR IN LISTS lst ITEMS other another)
    message(${VAR})
endforeach()

message("A while loop - using the list commmand with options")

set(lst2 1 2 3 4 5 6)
list(LENGTH lst2 COUNT)
while(COUNT)
    list(POP_FRONT lst2 CURRENT)
    message(${CURRENT})
    list(LENGTH lst2 COUNT)
endwhile()
message("There is no local scope in the while so count is still ["${COUNT} "] in global scope")

