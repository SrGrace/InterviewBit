'''

https://www.interviewbit.com/problems/simplify-directory-path/


Given an absolute path for a file (Unix-style), simplify it.

Examples:

path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Note that absolute path always begin with ‘/’ ( root directory )
Path will not have whitespace characters.

'''


class Solution:
    # @param A : string
    # @return a strings
    
    def simplifyPath(self, A):
        
        places = [p for p in A.split("/") if p!="." and p!=""]
        
        stack = []
        
        for p in places:
            if p == "..":
                if len(stack) > 0:
                    stack.pop()
            else:
                stack.append(p)
                
        return "/" + "/".join(stack)




