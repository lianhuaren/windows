#ifdef	WINDOWS
BYTE	AlsMap[128] = {
/*         0    1    2    3    4    5    6    7    8    9   */
/*        ---  ---  ---  ---  ---  ---  ---  ---  ---  ---  */
/*120*/                                           196, 197,
/*130*/   199, 201, 209, 214, 220, 225, 224, 226, 228, 227,
/*140*/   229, 231, 233, 232, 234, 235, 237, 236, 238, 239,
/*150*/   241, 243, 242, 244, 246, 245, 250, 249, 251, 252,
/*160*/   134, 176, 162, 163, 167, 149, 182, 223, 174, 169,
/*170*/   153, 180, 168, 1,   198, 216, 1,   177, 1,   1,
/*180*/   165, 181, 1,   1,   1,   1,   1,   170, 186, 1,
/*190*/   230, 248, 191, 161, 172, 1,   131, 1,   1,   171,
/*200*/   187, 133, 1,   192, 195, 213, 140, 156, 150, 151,
/*210*/   34,  34,  39,  39,  247, 1,   255, 159, 47,  164,
/*220*/   139, 155, 1,   1,   135, 149, 130, 132, 137, 194,
/*230*/   202, 193, 203, 200, 205, 206, 207, 204, 211, 212,
/*240*/   1,   210, 218, 219, 217, 185, 136, 152, 175, 1,
/*250*/   1,   176, 184, 1,   1,   1
};

/*
|	Old smart quote to True Type
| Changed to regular quotes for grammar checkers sake
|	210     147, 148, 145, 146, 1,   1,   255, 159, 47,  164,
*/

#endif
#ifdef MAC
BYTE	Win2Mac[256] = {
/*           0     1     2     3     4     5     6     7     8     9   */

/*  0*/      0,    1,    2,    3,    4,    5,    6,    7,    8,    9,
/* 10*/     10,   11,   12,   13,   14,   15,   16,   17,   18,   19,
/* 20*/     20,   21,   22,   23,   24,   25,   26,   27,   28,   29,
/* 30*/     30,   31,   32,   33,   34,   35,   36,   37,   38,   39,
/* 40*/     40,   41,   42,   43,   44,   45,   46,   47,   48,   49,
/* 50*/     50,   51,   52,   53,   54,   55,   56,   57,   58,   59,
/* 60*/     60,   61,   62,   63,   64,   65,   66,   67,   68,   69,
/* 70*/     70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
/* 80*/     80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
/* 90*/     90,   91,   92,   93,   94,   95,   96,   97,   98,   99,
/*100*/    100,  101,  102,  103,  104,  105,  106,  107,  108,  109,
/*110*/    110,  111,  112,  113,  114,  115,  116,  117,  118,  119,
/*120*/    120,  121,  122,  123,  124,  125,  126,  127,  		 
			 		  		  		 		 		 		 		 		 		 
/*           0     1     2     3     4     5     6     7     8     9   */
/*120*/                                                      1,    1,  
/*130*/      1,    1,    1,    1,    1,    1,    1,    1,    1,    1,  
/*140*/      1,    1,    1,    1,    1, 0xd4, 0xd5,    1,    1,    1,  
/*150*/      1,    1,    1,    1,    1,    1,    1,    1,    1,    1, 
/*160*/   0x20, 0xc1, 0xa2, 0xa3, 0xdb, 0xb4,    1, 0xa4, 0xac, 0xa9, 
/*170*/   0xbb, 0xc7, 0xc2, 0xd0, 0xa8, 0xd1, 0xa5, 0xb1,    1,    1, 
/*180*/   0xab, 0xb5, 0xa6, 0xa1,    1,    1, 0xbc, 0xc8,    1,    1, 
/*190*/      1, 0xc0, 0xcb, 0xe7, 0xe5, 0xcc, 0x80, 0x81, 0xae, 0x82, 
/*200*/   0xe9, 0x83, 0xe6, 0xe8, 0xed, 0xea, 0xeb, 0xec,    1, 0x84, 
/*210*/   0xf1, 0xee, 0xef, 0xcd, 0x85,    1, 0xaf, 0xf4, 0xf2, 0xf3, 
/*220*/   0x86,    1,    1, 0xa7, 0x88, 0x87, 0x89, 0x8b, 0x8a, 0x8c, 
/*230*/   0xce, 0x8d, 0x8f, 0x8e, 0x90, 0x91, 0x93, 0x92, 0x94, 0x95, 
/*240*/   0xb6, 0x96, 0x98, 0x97, 0x99, 0x9b, 0x9a, 0xd6, 0xbf, 0x9d, 
/*250*/   0x9c, 0x9e, 0x9f,    1,    1, 0xd8
};

BYTE	PC2Mac[256] = {
/*         0    1    2    3    4    5    6    7    8    9   */
/*  0*/     1,   1,   1, 169, 168, 167, 170, 183,   1,   1,  
/* 10*/     1,	  1,   1,   1,   1,   1,   1,   1,   1,   1, 
/* 20*/   166, 164,	 1,   1, 173, 175, 174, 172,   1, 171,	
/* 30*/     1,   1,  32,  33,  34,  35,  36,  37,  38,  39,
/* 40*/    40,  41,  42,  43,  44,  45,  46,  47,  48,  49,
/* 50*/    50,  51,  52,  53,  54,  55,  56,  57,  58,  59,
/* 60*/    60,  61,  62,  63,  64,  65,  66,  67,  68,  69,
/* 70*/    70,  71,  72,  73,  74,  75,  76,  77,  78,  79,
/* 80*/    80,  81,  82,  83,  84,  85,  86,  87,  88,  89,
/* 90*/    90,  91,  92,  93,  94,  95,  96,  97,  98,  99,
/*100*/   100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
/*110*/   110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
/*120*/   120, 121, 122, 123, 124, 125, 126, 127, 

/*120*/                                           130, 159, 
/*130*/   142, 137, 138, 136, 140, 141, 144, 145, 143, 149, 
/*140*/   148, 147, 128, 129, 131, 190, 174, 153, 154, 152, 
/*150*/   158, 157, 216, 133, 134, 162, 163, 180,   1,   1, 
/*160*/   135, 146, 151, 156, 150, 132, 187, 188, 192,   1, 
/*170*/   194,   1,   1, 193, 199, 200,   1,   1,   1, 189,  
/*180*/     1,   1,   1,   1,   1,   1,   1,   1,   1,   1,	
/*190*/     1,   1,   1,  94,   1,   1, 190,   1,   1,   1,  
/*200*/     1,   1,   1,   1,   1,   1,   1,   1,   1,   1,  
/*210*/     1,   1,   1,   1,   1,   1,   1,   1,   1,   1,  
/*220*/     1,   1,   1,   1, 181,  98,  71, 185,  83, 115, 
/*230*/   109, 116,  70,  81, 189, 100, 176,   1, 206, 199, 
/*240*/   186, 177, 179, 178, 243, 245, 214, 197, 161,   1, 
/*250*/   225, 195,   1,   1,   1,   1,
};
#endif

  
  
  











