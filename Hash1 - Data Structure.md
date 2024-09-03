***Data structure***
-
**Hash 1**
Develop Hash table using Separate Chaining which has following functions

 - Add data which contains key as integer and value as string
 - Find a value from a given key. If it is found, show its value. Otherwise, shows "-"
 -   This program can show all data in Hash table in format as follows:
    
    (key0,value0) (key01, value01) ... (key1,value1) (key11, value11) ... (key2,value2)  
    .....
    
    (keyn-1, valuen-1)  
    If there is no data, show -1 as key and "-" as value.
- Define size of Hash Table to 17

***Input***
- each line consists of `command` `key` `value`
- Command:  
    a : add a pair of `key,value` into Hash Table  
    p : show a pair of `key,value`
    s : find a value from a given key 
    e : exit

***Example***
 - a 13 cat : add key = 13 and value = cat  
 - a 17 dog : add key = 17 and value = dog  
 - p : show pair of `key,value` in Hash. If there are chain, use space as delimiter to separate each pair of `key,value `
 - s13 : find a value from key = 13  
- s30 : find a value from key = 30  
- e : exit

| Input | Output |
|---|---|
| a 1415 xxxt|(-1,-)
| a 1712 yyyt|(2041,yout)	
| a 2041 yout|(-1,-)
| p|(-1,-)
| a 2158 onit |(1415,xxxt)
| a 3619 eggt |(-1,-)
| a 1896 godt |(-1,-)
| p|(-1,-)
| a 3010 nomt |(-1,-)
| a 2589 xdf  |(-1,-)
| p  |(-1,-)
| a 7741 rae|(-1,-)
| a 3654 eeec |(1712,yyyt)
| p|(-1,-)
| s 2521|(-1,-)
| s 2158|(-1,-)
| s 3010|(-1,-)
| s 3629|(-1,-)
| s 1234 |(2041,yout)
| e  | (-1,-) 
| | (-1,-)
| | (1415,xxxt)
| | (-1,-)
| | (-1,-)
| | (-1,-)
| | (-1,-)
| | (1896,godt)
| | (-1,-)
| | (-1,-)
| | (1712,yyyt)
| | (-1,-)
| | (-1,-)
| | (3619,eggt)
| | (2158,onit)
| | (-1,-)
| | (2041,yout)(3010,nomt)
| | (-1,-)
| | (-1,-)
| | (1415,xxxt)
| | (2589,xdf)
| | (-1,-)
| | (-1,-)
| | (-1,-)
| | (1896,godt)
| | (-1,-)
| | (-1,-)
| | (1712,yyyt)
| | (-1,-)
| | (-1,-)
| | (3619,eggt)
| | (2158,onit)
| | (-1,-)
| | (2041,yout)(3010,nomt)
| | (-1,-)
| | (-1,-)
| | (1415,xxxt)
| | (2589,xdf)
| | (7741,rae)
| | (-1,-)
| | (-1,-)
| | (1896,godt)
| | (-1,-)
| | (-1,-)
| | (1712,yyyt)
| | (-1,-)
| | (-1,-)
| | (3619,eggt)
| | (2158,onit)(3654,eeec)
| | -
| | onit
| | nomt
| | -
||


