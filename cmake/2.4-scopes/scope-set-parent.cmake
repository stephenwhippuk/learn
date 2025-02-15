cmake_minimum_required(VERSION 3.26)
set(V 1)
message("> Global: ${V}")
block() # outer block
 message(" > Outer: ${V}")
 set(V 2)
 block() # inner block
   message("  > Inner: ${V}")
   set(V 3, PARENT_SCOPE) # using parent scope has the same effect as propagate 
   message("  < Inner: ${V}")
 endblock()
 message(" < Outer: ${V}")
endblock()
message("< Global: ${V}")