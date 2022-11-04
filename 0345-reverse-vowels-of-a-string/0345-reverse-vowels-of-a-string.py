class Solution:
    
    def isVowel(self,ch):
        
        if(ch=='a' or ch=='e' or ch=='i' or  ch=='o' or  ch=='u' or  ch=='A' or  ch=='E' or  ch=='I' or  ch=='O' or  ch=='U'):
            return True
        return False
    
    
    
    def reverseVowels(self, s: str) -> str:
        
        n=len(s)
        s=list(s)
        st=0
        e=n-1
        
        while st<e:
            
            while(st<e and self.isVowel(s[st])==False):
                st+=1
                
            while(st<e and self.isVowel(s[e])==False):
                e-=1
                
            s[st],s[e]=s[e],s[st]
            st+=1
            e-=1
        return "".join(s)
        