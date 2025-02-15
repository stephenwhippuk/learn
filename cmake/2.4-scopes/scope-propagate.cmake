cmake_minimum_required(VERSION 3.26)
set(V 1)
message("> Global: ${V}")
block() # outer block
 message(" > Outer: ${V}")
 set(V 2)
 block(PROPAGATE V) # inner block will now SET the value of V in the outer block but not Global  
   message("  > Inner: ${V}")
   set(V 3)
   message("  < Inner: ${V}")
 endblock()
 message(" < Outer: ${V}")
endblock()
message("< Global: ${V}")