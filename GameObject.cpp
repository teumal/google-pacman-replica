
// GameObject.cpp

# include"GameObject.hpp"


//////////////////////
// Node::           //
//////////////////////


const Node Node::map[323] = {
   {20, 25+ADJ,0, {INVALID, 1, 58,      INVALID} }, // [0]
   {44, 25+ADJ,1, {INVALID, 2, INVALID, 0      } }, // [1]
   {68, 25+ADJ,2, {INVALID, 3, INVALID, 1      } }, // [2]
   {91, 25+ADJ,3, {INVALID, 4, INVALID, 2      } }, // [3]
   {115,25+ADJ,4, {INVALID ,5, 299,     3      } }, // [4]

   {139,25+ADJ,5, {INVALID, 6,  INVALID, 4} }, // [5]
   {162,25+ADJ,6, {INVALID, 7,  INVALID, 5} }, // [6]
   {185,25+ADJ,7, {INVALID, 8,  INVALID, 6} }, // [7]
   {208,25+ADJ,8, {INVALID, 9,  INVALID, 7} }, // [8]
   {231,25+ADJ,9, {INVALID, 10, INVALID, 8} }, // [9]

   {254,25+ADJ,10, {INVALID, 11, INVALID, 9 } }, // [10]
   {278,25+ADJ,11, {INVALID, 12, INVALID, 10} }, // [11]
   {299,25+ADJ,12, {INVALID, 13, INVALID, 11} }, // [12]
   {325,25+ADJ,13, {INVALID, 14, INVALID, 12} }, // [13]
   {350,25+ADJ,14, {INVALID, 15, 65,      13} }, // [14]

   {376,25+ADJ,15, {INVALID, 16, INVALID, 14} }, // [15]
   {401,25+ADJ,16, {INVALID, 17, INVALID, 15} }, // [16]
   {423,25+ADJ,17, {INVALID, 18, INVALID, 16} }, // [17]
   {448,25+ADJ,18, {INVALID, 19, INVALID, 17} }, // [18]
   {472,25+ADJ,19, {INVALID, 20, INVALID, 18} }, // [19]

   {496,25+ADJ,20, {INVALID, 21, INVALID, 19} }, // [20]
   {520,25+ADJ,21, {INVALID, 22, INVALID, 20} }, // [21]
   {545,25+ADJ,22, {INVALID, 23, INVALID, 21} }, // [22]
   {568,25+ADJ,23, {INVALID, 24, INVALID, 22} }, // [23]
   {592,25+ADJ,24, {INVALID, 25, INVALID, 23} }, // [24]

   {616,25+ADJ,25, {INVALID, 26, INVALID, 24} }, // [25]
   {640,25+ADJ,26, {INVALID, 27, INVALID, 25} }, // [26]
   {664,25+ADJ,27, {INVALID, 28, INVALID, 26} }, // [27]
   {688,25+ADJ,28, {INVALID, 29, INVALID, 27} }, // [28]
   {711,25+ADJ,29, {INVALID, 30, INVALID, 28} }, // [29]

   {735,25+ADJ,30, {INVALID, 31, 84,      29} }, // [30]
   {758,25+ADJ,31, {INVALID, 32, INVALID, 30} }, // [31]
   {781,25+ADJ,32, {INVALID, 33, INVALID, 31} }, // [32]
   {804,25+ADJ,33, {INVALID, 34, INVALID, 32} }, // [33]
   {827,25+ADJ,34, {INVALID, 35, INVALID, 33} }, // [34]

   {850,25+ADJ,35, {INVALID, 36, INVALID, 34} }, // [35]
   {873,25+ADJ,36, {INVALID, 37, INVALID, 35} }, // [36]
   {896,25+ADJ,37, {INVALID, 38, INVALID, 36} }, // [37]
   {919,25+ADJ,38, {INVALID, 39, INVALID, 37} }, // [38]
   {950,25+ADJ,39, {INVALID, 40, 259,     38} }, // [39]

   {973, 25+ADJ,40, {INVALID, 41, INVALID, 39} }, // [40]
   {996, 25+ADJ,41, {INVALID, 42, INVALID, 40} }, // [41]
   {1019,25+ADJ,42, {INVALID, 43, INVALID, 41} }, // [42]
   {1045,25+ADJ,43, {INVALID, 44, 86,      42} }, // [43]
   {1068,25+ADJ,44, {INVALID, 45, INVALID, 43} }, // [44]

   {1091,25+ADJ,45, {INVALID, 46, INVALID, 44} }, // [45]
   {1114,25+ADJ,46, {INVALID, 47, INVALID, 45} }, // [46]
   {1137,25+ADJ,47, {INVALID, 48, INVALID, 46} }, // [47]
   {1160,25+ADJ,48, {INVALID, 49, INVALID, 47} }, // [48]
   {1190,25+ADJ,49, {INVALID, 50, 89,      48} }, // [49]

   {1213,25+ADJ,50, {INVALID, 51, INVALID, 49} }, // [50]
   {1236,25+ADJ,51, {INVALID, 52, INVALID, 50} }, // [51]
   {1259,25+ADJ,52, {INVALID, 53, INVALID, 51} }, // [52]
   {1282,25+ADJ,53, {INVALID, 54, INVALID, 52} }, // [53]
   {1305,25+ADJ,54, {INVALID, 55, INVALID, 53} }, // [54]

   {1330,25+ADJ,55, {INVALID, INVALID, 56, 54     } }, // [55]
   {1330,48+ADJ,56, {55,      INVALID, 57, INVALID} }, // [56]
   {1330,71+ADJ,57, {56,      INVALID, 95, INVALID} }, // [57]
   {20,  48+ADJ,58, {0,       INVALID, 59, INVALID} }, // [58]
   {20,  73+ADJ,59, {58,      INVALID, 60, INVALID} }, // [59]

   {20, 95+ADJ,60, {59,      61,      INVALID, INVALID} }, // [60]
   {43, 95+ADJ,61, {INVALID, 62,      INVALID, 60     } }, // [61]
   {66, 95+ADJ,62, {INVALID, 63,      INVALID, 61     } }, // [62]
   {89, 95+ADJ,63, {INVALID, 64,      INVALID, 62     } }, // [63]
   {115,95+ADJ,64, {300,     INVALID, 103,     63     } }, // [64]

   {350,48+ADJ,65, {14,      INVALID, 66,      INVALID} }, // [65]
   {350,71+ADJ,66, {65,      INVALID, 67,      INVALID} }, // [66]
   {350,95+ADJ,67, {66,      68,      96,      INVALID} }, // [67]
   {374,95+ADJ,68, {INVALID, 69,      INVALID, 67     } }, // [68]
   {398,95+ADJ,69, {INVALID, 70,      INVALID, 68     } }, // [69]

   {422,95+ADJ,70, {INVALID, 71, INVALID, 69} }, // [70]
   {446,95+ADJ,71, {INVALID, 72, INVALID, 70} }, // [71]
   {470,95+ADJ,72, {INVALID, 73, INVALID, 71} }, // [72]
   {494,95+ADJ,73, {INVALID, 74, INVALID, 72} }, // [73]
   {518,95+ADJ,74, {INVALID, 75, INVALID, 73} }, // [74]

   {545,95+ADJ,75, {INVALID, 76, 268,     74} }, // [75]
   {569,95+ADJ,76, {INVALID, 77, INVALID, 75} }, // [76]
   {593,95+ADJ,77, {INVALID, 78, INVALID, 76} }, // [77]
   {617,95+ADJ,78, {INVALID, 79, INVALID, 77} }, // [78]
   {641,95+ADJ,79, {INVALID, 80, INVALID, 78} }, // [79]

   {665,95+ADJ,80, {INVALID, 81,      INVALID, 79     } }, // [80]
   {689,95+ADJ,81, {INVALID, 82,      INVALID, 80     } }, // [81]
   {713,95+ADJ,82, {INVALID, 83,      INVALID, 81     } }, // [82]
   {735,95+ADJ,83, {85,      262,     110,     82     } }, // [83]
   {735,49+ADJ,84, {30,      INVALID, 85,      INVALID} }, // [84]

   {735, 73+ADJ,85, {84, INVALID, 83,  INVALID} }, // [85]
   {1045,49+ADJ,86, {43, INVALID, 87,  INVALID} }, // [86]
   {1045,73+ADJ,87, {86, INVALID, 88,  INVALID} }, // [87]
   {1045,95+ADJ,88, {87, 254,     160, INVALID} }, // [88]

   {1190,49+ADJ,89, {49,      INVALID, 90,      INVALID} }, // [89]
   {1190,73+ADJ,90, {89,      INVALID, 91,      INVALID} }, // [90]
   {1190,95+ADJ,91, {90,      252,     INVALID, 258    } }, // [91]
   {1259,95+ADJ,92, {INVALID, 93,      INVALID, 253    } }, // [92]
   {1283,95+ADJ,93, {INVALID, 94,      INVALID, 92     } }, // [93]

   {1307,95+ADJ,94, {INVALID, 95,      INVALID, 93     } }, // [94]
   {1330,95+ADJ,95, {57,      INVALID, INVALID, 94     } }, // [95]
   {350,120+ADJ,96, {67,      INVALID, 97,      296    } }, // [96]
   {350,144+ADJ,97, {96,      INVALID, 98,      INVALID} }, // [97]
   {350,168+ADJ,98, {97,      INVALID, 99,      INVALID} }, // [98]

   {350,192+ADJ,99,  {98,  INVALID, 100, INVALID} }, // [99]
   {350,216+ADJ,100, {99,  INVALID, 101, INVALID} }, // [100]
   {350,240+ADJ,101, {100, INVALID, 102, INVALID} }, // [101]
   {350,264+ADJ,102, {101, INVALID, 139, INVALID} }, // [102]

   {115,119+ADJ,103, {64,  INVALID, 104, INVALID} }, // [103]
   {115,143+ADJ,104, {103, INVALID, 105, INVALID} }, // [104]
   {115,167+ADJ,105, {104, INVALID, 106, INVALID} }, // [105]
   {115,190+ADJ,106, {105, INVALID, 135, 321    } }, // [106]

   {210,190+ADJ,107,     {298,     108,     INVALID, INVALID} }, // [107]
   {233,190+ADJ,108,     {INVALID, 109,     INVALID, 107    } }, // [108]
   {250,190+ADJ,109,     {INVALID, INVALID, INVALID, 108    } }, // [109]
   {735,119+ADJ,INVALID, {83,      INVALID, 111,     INVALID} }, // [110]
   {735,143+ADJ,INVALID, {110,     INVALID, 112,     INVALID} }, // [111]

   {735,167+ADJ,INVALID, {111, INVALID, 113, INVALID} }, // [112]
   {735,191+ADJ,INVALID, {112, INVALID, 114, INVALID} }, // [113]
   {735,215+ADJ,INVALID, {113, INVALID, 115, INVALID} }, // [114]
   {735,235+ADJ,INVALID, {114, 244,     282, INVALID} }, // [115]
   {950,119+ADJ,INVALID, {320, INVALID, 117, INVALID} }, // [116]

   {950,143+ADJ,INVALID, {116, INVALID, 118, INVALID} }, // [117]
   {950,167+ADJ,INVALID, {117, INVALID, 119, INVALID} }, // [118]
   {950,191+ADJ,INVALID, {118, INVALID, 120, INVALID} }, // [119]
   {950,215+ADJ,INVALID, {119, INVALID, 121, INVALID} }, // [120]
   {950,235+ADJ,INVALID, {120, INVALID, 158, 251    } }, // [121]

   {1140,215+ADJ,122, {INVALID, 123,     INVALID, INVALID} }, // [122]
   {1164,215+ADJ,123, {INVALID, 124,     INVALID, 122    } }, // [123]
   {1188,215+ADJ,124, {INVALID, 125,     INVALID, 123    } }, // [124]
   {1212,215+ADJ,125, {INVALID, 126,     INVALID, 124    } }, // [125]
   {1235,215+ADJ,126, {130,     INVALID, 313,     125    } }, // [126]

   {1235,119+ADJ,127, {253,     INVALID, 128, INVALID} }, // [127]
   {1235,143+ADJ,128, {127,     INVALID, 129, INVALID} }, // [128]
   {1235,167+ADJ,129, {128,     INVALID, 130, INVALID} }, // [129]
   {1235,190+ADJ,130, {129,     308,     126, INVALID} }, // [130]
   {20,  285+ADJ,131, {INVALID, 132,     180, INVALID} }, // [131]

   {44, 285+ADJ,132, {INVALID, 133,     INVALID, 131    } }, // [132]
   {68, 285+ADJ,133, {INVALID, 134,     INVALID, 132    } }, // [133]
   {92, 285+ADJ,134, {INVALID, 138,     INVALID, 133    } }, // [134]
   {115,214+ADJ,135, {106,     INVALID, 136,     INVALID} }, // [135]
   {115,238+ADJ,136, {135,     INVALID, 137,     INVALID} }, // [136]

   {115,262+ADJ,137, {136,     INVALID, 138,     INVALID} }, // [137]
   {115,285+ADJ,138, {137,     183,     INVALID, 134    } }, // [138]
   {350,285+ADJ,139, {102,     140,     INVALID, 157    } }, // [139]
   {375,285+ADJ,140, {INVALID, 141,     INVALID, 139    } }, // [140]
   {400,285+ADJ,141, {INVALID, 301,     142,     140    } }, // [141]

   {400,309+ADJ,142, {141,     INVALID, 143, INVALID} }, // [142]
   {400,333+ADJ,143, {142,     INVALID ,197, INVALID} }, // [143]
   {475,285+ADJ,144, {INVALID, 147,     145, 302    } }, // [144]
   {475,309+ADJ,145, {144,     INVALID, 146, INVALID} }, // [145]
   {475,333+ADJ,146, {145,     INVALID, 198, INVALID} }, // [146]

   {499,285+ADJ,147, {INVALID, 148, INVALID, 144} }, // [147]
   {523,285+ADJ,148, {INVALID, 149, INVALID, 147} }, // [148]
   {545,285+ADJ,149, {274,     275, INVALID, 148} }, // [149]
   {160,285+ADJ,150, {INVALID, 151, INVALID, 183} }, // [150]
   {185,285+ADJ,151, {INVALID, 152, INVALID, 150} }, // [151]

   {209,285+ADJ,152, {INVALID, 153, INVALID, 151} }, // [152]
   {234,285+ADJ,153, {INVALID, 154, INVALID, 152} }, // [153]
   {257,285+ADJ,154, {INVALID, 155, INVALID, 153} }, // [154]
   {282,285+ADJ,155, {INVALID, 156, INVALID, 154} }, // [155]
   {305,285+ADJ,156, {INVALID, 157, INVALID, 155} }, // [156]

   {329,285+ADJ, 157,     {INVALID, 139,     INVALID, 156    } }, // [157]
   {950,261+ADJ, INVALID, {121,     INVALID, 159,     INVALID} }, // [158]
   {950,285+ADJ, 159,     {158,     284,     219,     INVALID} }, // [159]
   {1045,119+ADJ,160,     {88,      INVALID, 161,     INVALID} }, // [160]
   {1045,143+ADJ,161,     {160,     INVALID, 162,     INVALID} }, // [161]

   {1045,167+ADJ,162, {161, INVALID, 163, INVALID} }, // [162]
   {1045,191+ADJ,163, {162, INVALID, 164, INVALID} }, // [163]
   {1045,215+ADJ,164, {163, INVALID, 165, INVALID} }, // [164]
   {1045,239+ADJ,165, {164, INVALID, 166, INVALID} }, // [165]
   {1045,263+ADJ,166, {165, INVALID, 167, INVALID} }, // [166]

   {1045,285+ADJ,167, {166,     168, INVALID, 286} }, // [167]
   {1069,285+ADJ,168, {INVALID, 169, INVALID, 167} }, // [168]
   {1093,285+ADJ,169, {INVALID, 170, INVALID, 168} }, // [169]
   {1117,285+ADJ,170, {INVALID, 171, INVALID, 169} }, // [170]
   {1141,285+ADJ,171, {INVALID, 172, INVALID, 170} }, // [171]

   {1165,285+ADJ,172, {INVALID, 173, INVALID, 171} }, // [172]
   {1185,285+ADJ,173, {INVALID, 174, 315,     172} }, // [173]
   {1211,285+ADJ,174, {INVALID, 175, INVALID, 173} }, // [174]
   {1235,285+ADJ,175, {314,     176, INVALID, 174} }, // [175]
   {1259,285+ADJ,176, {INVALID, 177, INVALID, 175} }, // [176]

   {1283,285+ADJ,177, {INVALID, 178,     INVALID, 176    } }, // [177]
   {1307,285+ADJ,178, {INVALID, 179,     INVALID, 177    } }, // [178]
   {1330,285+ADJ,179, {INVALID, INVALID, 238,     178    } }, // [179]
   {20,  309+ADJ,180, {131,     INVALID, 181,     INVALID} }, // [180]
   {20,  331+ADJ,181, {180,     INVALID, 182,     INVALID} }, // [181]

   {20, 355+ADJ,182, {181,     287,     INVALID, INVALID} }, // [182]
   {135,285+ADJ,183, {INVALID, 150    , 184,     138    } }, // [183]
   {135,309+ADJ,184, {183,     INVALID, 185,     INVALID} }, // [184]
   {135,333+ADJ,185, {184,     INVALID, 186,     INVALID} }, // [185]
   {135,355+ADJ,186, {185,     187,     INVALID, 290    } }, // [186]

   {159,355+ADJ,187, {INVALID, 188, INVALID, 186} }, // [187]
   {183,355+ADJ,188, {INVALID, 189, INVALID, 187} }, // [188]
   {207,355+ADJ,189, {INVALID, 190, INVALID, 188} }, // [189]
   {231,355+ADJ,190, {INVALID, 191, INVALID, 189} }, // [190]
   {255,355+ADJ,191, {INVALID, 192, INVALID, 190} }, // [191]

   {279,355+ADJ,192, {INVALID, 193, INVALID, 191} }, // [192]
   {303,355+ADJ,193, {INVALID, 194, INVALID, 192} }, // [193]
   {327,355+ADJ,194, {INVALID, 195, INVALID, 193} }, // [194]
   {351,355+ADJ,195, {INVALID, 196, INVALID, 194} }, // [195]
   {375,355+ADJ,196, {INVALID, 197, INVALID, 195} }, // [196]

   {400,355+ADJ,197, {143,     INVALID, INVALID, 196    } }, // [197]
   {475,355+ADJ,198, {146,     199,     INVALID, INVALID} }, // [198]
   {499,355+ADJ,199, {INVALID, 200,     INVALID, 198    } }, // [199]
   {523,355+ADJ,200, {INVALID, 201,     INVALID, 199    } }, // [200]
   {547,355+ADJ,201, {INVALID, 202,     INVALID, 200    } }, // [201]

   {571,355+ADJ,202, {INVALID, 203, INVALID, 201} }, // [202]
   {595,355+ADJ,203, {INVALID, 204, INVALID, 202} }, // [203]
   {619,355+ADJ,204, {INVALID, 205, INVALID, 203} }, // [204]
   {643,355+ADJ,205, {INVALID, 206, INVALID, 204} }, // [205]
   {667,355+ADJ,206, {INVALID, 207, INVALID, 205} }, // [206]

   {691,355+ADJ,207, {INVALID, 208,     INVALID, 206    } }, // [207]
   {715,355+ADJ,208, {INVALID, 209,     INVALID, 207    } }, // [208]
   {735,355+ADJ,209, {210,     INVALID, INVALID, 208    } }, // [209]
   {735,332+ADJ,210, {240,     INVALID, 209,     INVALID} }, // [210]
   {805,333+ADJ,211, {243,     INVALID, 212,     INVALID} }, // [211]

   {805,355+ADJ,212, {211,     213,     INVALID, INVALID} }, // [212]
   {840,355+ADJ,213, {INVALID, 216,     INVALID, 212    } }, // [213]
   {880,310+ADJ,214, {INVALID, 217,     215,     INVALID} }, // [214]
   {880,333+ADJ,215, {214,     INVALID, 216,     INVALID} }, // [215]
   {880,355+ADJ,216, {215,     INVALID, INVALID, 213    } }, // [216]

   {904,310+ADJ,217, {INVALID, 218,     INVALID, 214    } }, // [217]
   {928,310+ADJ,218, {INVALID, 219,     INVALID, 217    } }, // [218]
   {950,310+ADJ,219, {159,     INVALID, 220,     218    } }, // [219]
   {950,333+ADJ,220, {219,     INVALID, 221,     INVALID} }, // [220]
   {950,355+ADJ,221, {220,     222,     INVALID, INVALID} }, // [221]

   {974, 355+ADJ,222, {INVALID, 223, INVALID, 221} }, // [222]
   {998, 355+ADJ,223, {INVALID, 224, INVALID, 222} }, // [223]
   {1022,355+ADJ,224, {INVALID, 225, INVALID, 223} }, // [224]
   {1046,355+ADJ,225, {INVALID, 226, INVALID, 224} }, // [225]
   {1070,355+ADJ,226, {INVALID, 227, INVALID, 225} }, // [226]

   {1094,355+ADJ,227, {INVALID, 228, INVALID, 226} }, // [227]
   {1118,355+ADJ,228, {INVALID, 229, INVALID, 227} }, // [228]
   {1142,355+ADJ,229, {INVALID, 230, INVALID, 228} }, // [229]
   {1166,355+ADJ,230, {INVALID, 231, INVALID, 229} }, // [230]
   {1185,355+ADJ,231, {316,     232, INVALID, 230} }, // [231]

   {1209,355+ADJ,232, {INVALID, 233, INVALID, 231} }, // [232]
   {1233,355+ADJ,233, {INVALID, 234, INVALID, 232} }, // [233]
   {1257,355+ADJ,234, {INVALID, 235, INVALID, 233} }, // [234]
   {1281,355+ADJ,235, {INVALID, 236, INVALID, 234} }, // [235]
   {1305,355+ADJ,236, {INVALID, 237, INVALID, 235} }, // [236]

   {1330,355+ADJ,237, {239,     INVALID, INVALID, 236    } }, // [237]
   {1330,309+ADJ,238, {179,     INVALID, 239,     INVALID} }, // [238]
   {1330,330+ADJ,239, {238,     INVALID, 237,     INVALID} }, // [239]
   {735, 310+ADJ,240, {283,     241,     210,     INVALID} }, // [240]
   {759, 310+ADJ,241, {INVALID, 242,     INVALID, 240    } }, // [241]

   {783,310+ADJ,242,     {INVALID ,243,     INVALID, 241} }, // [242]
   {805,310+ADJ,243,     {INVALID, INVALID, 211,     242} }, // [243]
   {759,235+ADJ,INVALID, {INVALID, 245,     INVALID, 115} }, // [244]
   {783,235+ADJ,INVALID, {INVALID, 246,     INVALID, 244} }, // [245]
   {807,235+ADJ,INVALID, {INVALID, 247,     INVALID, 245} }, // [246]

   {831,235+ADJ,INVALID, {INVALID, 248, INVALID, 246} }, // [247]
   {855,235+ADJ,INVALID, {INVALID, 249, INVALID, 247} }, // [248]
   {879,235+ADJ,INVALID, {INVALID, 250, INVALID, 248} }, // [249]
   {903,235+ADJ,INVALID, {INVALID, 251, INVALID, 249} }, // [250]
   {927,235+ADJ,INVALID, {INVALID, 121, INVALID, 250} }, // [251]

   {1211,95+ADJ,252, {INVALID, 253, INVALID, 91 } }, // [252]
   {1235,95+ADJ,253, {INVALID, 92,  127,     252} }, // [253]
   {1069,95+ADJ,254, {INVALID, 255, INVALID, 88 } }, // [254]
   {1093,95+ADJ,255, {INVALID, 256, INVALID, 254} }, // [255]
   {1117,95+ADJ,256, {INVALID, 257, INVALID, 255} }, // [256]

   {1141,95+ADJ,257,     {INVALID, 258,     INVALID, 256    } }, // [257]
   {1165,95+ADJ,258,     {INVALID, 91,      INVALID, 257    } }, // [258]
   {950, 49+ADJ,INVALID, {39,      INVALID, 260,     INVALID} }, // [259]
   {950, 73+ADJ,INVALID, {259,     INVALID, 320,     INVALID} }, // [260]
   {840, 95+ADJ,INVALID, {INVALID, 265,     318,     264    } }, // [261]

   {759,95+ADJ,INVALID, {INVALID, 263, INVALID, 83 } }, // [262]
   {783,95+ADJ,INVALID, {INVALID, 264, INVALID, 262} }, // [263]
   {807,95+ADJ,INVALID, {INVALID, 261, INVALID, 263} }, // [264]
   {873,95+ADJ,INVALID, {INVALID, 266, INVALID, 261} }, // [265]
   {898,95+ADJ,INVALID, {INVALID, 267, INVALID, 265} }, // [266]

   {921,95+ADJ, INVALID, {INVALID, 320,     INVALID, 266    } }, // [267]
   {545,119+ADJ,268,     {75,      INVALID, 269,     INVALID} }, // [268]
   {545,143+ADJ,269,     {268,     INVALID, 270,     INVALID} }, // [269]
   {545,167+ADJ,270,     {269,     INVALID, 271,     INVALID} }, // [270]
   {545,191+ADJ,271,     {270,     INVALID, 272,     INVALID} }, // [271]

   {545,215+ADJ,272, {271,     INVALID, 273,     INVALID} }, // [272]
   {545,239+ADJ,273, {272,     INVALID, 274,     INVALID} }, // [273]
   {545,263+ADJ,274, {273,     INVALID, 149,     INVALID} }, // [274]
   {569,285+ADJ,275, {INVALID, 276,     INVALID, 149    } }, // [275]
   {593,285+ADJ,276, {INVALID, 277,     INVALID, 275    } }, // [276]

   {617,285+ADJ,277,     {INVALID, 278,     INVALID, 276    } }, // [277]
   {641,285+ADJ,278,     {INVALID, 279,     INVALID, 277    } }, // [278]
   {665,285+ADJ,279,     {INVALID, 280,     INVALID, 278    } }, // [279]
   {689,285+ADJ,280,     {INVALID, 281,     INVALID, 279    } }, // [280]
   {713,285+ADJ,281,     {INVALID, 283,     INVALID, 280    } }, // [281]
   {735,261+ADJ,INVALID, {115,     INVALID, 283,     INVALID} }, // [282]

   {735, 285+ADJ,283, {282,     INVALID, 240,     281} }, // [283]
   {974, 285+ADJ,284, {INVALID, 285,     INVALID, 159} }, // [284]
   {998, 285+ADJ,285, {INVALID, 286,     INVALID, 284} }, // [285]
   {1022,285+ADJ,286, {INVALID, 167,     INVALID, 285} }, // [286]
   {44,  355+ADJ,287, {INVALID, 288,     INVALID, 182} }, // [287]

   {68, 355+ADJ,288, {INVALID, 289, INVALID, 287    } }, // [288]
   {92, 355+ADJ,289, {INVALID, 290, INVALID, 288    } }, // [289]
   {116,355+ADJ,290, {INVALID, 186, INVALID, 289    } }, // [290]
   {210,120+ADJ,291, {INVALID, 292, 297,     INVALID} }, // [291]
   {234,120+ADJ,292, {INVALID, 293, INVALID, 291    } }, // [292]

   {258,120+ADJ,293, {INVALID, 294,     INVALID, 292    } }, // [293]
   {282,120+ADJ,294, {INVALID, 295,     INVALID, 293    } }, // [294]
   {306,120+ADJ,295, {INVALID, 296,     INVALID, 294    } }, // [295]
   {330,120+ADJ,296, {INVALID, 96,      INVALID, 295    } }, // [296]
   {210,144+ADJ,297, {291,     INVALID, 298,     INVALID} }, // [297]

   {210,168+ADJ,298, {297,     INVALID, 107,    INVALID} }, // [298]
   {115,49+ADJ, 299, {4,       INVALID, 300,    INVALID} }, // [299]
   {115,73+ADJ, 300, {299,     INVALID, 64,     INVALID} }, // [300]
   {424,285+ADJ,301, {INVALID, 302,    INVALID, 141    } }, // [301]
   {448,285+ADJ,302, {INVALID, 144,    INVALID, 301    } }, // [302]

   {-36,190+ADJ,INVALID, {INVALID, 304, INVALID, 312} }, // [303]
   {-3,190+ADJ, INVALID, {INVALID, 305, INVALID, 303} }, // [304]
   {20, 190+ADJ,INVALID, {INVALID, 306, INVALID, 304} }, // [305]
   {43, 190+ADJ,INVALID, {INVALID, 307, INVALID, 305} }, // [306]
   {66, 190+ADJ,INVALID, {INVALID, 321, INVALID, 306} }, // [307]

   {1259,190+ADJ,INVALID, {INVALID, 309, INVALID, 130} }, // [308]
   {1283,190+ADJ,INVALID, {INVALID, 310, INVALID, 308} }, // [309]
   {1307,190+ADJ,INVALID, {INVALID, 311, INVALID, 309} }, // [310]
   {1331,190+ADJ,INVALID, {INVALID, 312, INVALID, 310} }, // [311]
   {1380,190+ADJ,INVALID, {INVALID, 303, INVALID, 311} }, // [312]

   {1235,239+ADJ,313,     {126,     INVALID, 314,     INVALID} }, // [313]
   {1235,263+ADJ,314,     {313,     INVALID, 175,     INVALID} }, // [314]
   {1185,309+ADJ,315,     {173,     INVALID, 316,     INVALID} }, // [315]
   {1185,333+ADJ,316,     {315,     INVALID, 231,     INVALID} }, // [316]
   {790, 170+ADJ,INVALID, {INVALID, 318,     INVALID, INVALID} }, // [317]

   {840,170+ADJ,INVALID, {261,     319,     INVALID, 317} }, // [318]
   {890,170+ADJ,INVALID, {INVALID, INVALID, INVALID, 318} }, // [319]
   {950,95+ADJ, INVALID, {260,     INVALID, 116,     267} }, // [320]
   {89, 190+ADJ,INVALID, {INVALID, 106,     INVALID, 307} }  // [321]
};


//////////////////////
// Cookie::         //
//////////////////////


Cookie Cookie::data[] = {
   {33,39+ADJ,10,10, CookieType::NORM, true},  // [0]
   {57,39+ADJ,10,10, CookieType::NORM, true},  // [1]
   {81,39+ADJ,10,10, CookieType::NORM, true},  // [2]
   {105,39+ADJ,10,10, CookieType::NORM, true}, // [3]
   {129,39+ADJ,10,10, CookieType::NORM, true}, // [4]

   {152,39+ADJ,10,10, CookieType::NORM, true}, // [5]
   {175,39+ADJ,10,10, CookieType::NORM, true}, // [6]
   {198,39+ADJ,10,10, CookieType::NORM, true}, // [7]
   {221,39+ADJ,10,10, CookieType::NORM, true}, // [8]
   {244,39+ADJ,10,10, CookieType::NORM, true}, // [9]

   {267,39+ADJ,10,10, CookieType::NORM, true}, // [10]
   {290,39+ADJ,10,10, CookieType::NORM, true}, // [11]
   {313,39+ADJ,10,10, CookieType::NORM, true}, // [12]
   {338,39+ADJ,10,10, CookieType::NORM, true}, // [13]
   {365,39+ADJ,10,10, CookieType::NORM, true}, // [14]

   {389,39+ADJ,10,10, CookieType::NORM, true}, // [15]
   {413,39+ADJ,10,10, CookieType::NORM, true}, // [16]
   {437,39+ADJ,10,10, CookieType::NORM, true}, // [17]
   {461,39+ADJ,10,10, CookieType::NORM, true}, // [18]
   {485,39+ADJ,10,10, CookieType::NORM, true}, // [19]

   {509,39+ADJ,10,10, CookieType::NORM, true}, // [20]
   {533,39+ADJ,10,10, CookieType::NORM, true}, // [21]
   {557,39+ADJ,10,10, CookieType::NORM, true}, // [22]
   {581,39+ADJ,10,10, CookieType::NORM, true}, // [23]
   {605,39+ADJ,10,10, CookieType::NORM, true}, // [24]

   {629,39+ADJ,10,10, CookieType::NORM, true}, // [25]
   {653,39+ADJ,10,10, CookieType::NORM, true}, // [26]
   {677,39+ADJ,10,10, CookieType::NORM, true}, // [27]
   {701,39+ADJ,10,10, CookieType::NORM, true}, // [28]
   {725,39+ADJ,10,10, CookieType::NORM, true}, // [29]
   {749,39+ADJ,10,10, CookieType::NORM, true}, // [30]

   {772,39+ADJ,10,10, CookieType::NORM, true}, // [31]
   {795,39+ADJ,10,10, CookieType::NORM, true}, // [32]
   {818,39+ADJ,10,10, CookieType::NORM, true}, // [33]
   {841,39+ADJ,10,10, CookieType::NORM, true}, // [34]
   {864,39+ADJ,10,10, CookieType::NORM, true}, // [35]

   {887,39+ADJ,10,10, CookieType::NORM, true}, // [36]
   {910,39+ADJ,10,10, CookieType::NORM, true}, // [37]
   {933,39+ADJ,10,10, CookieType::NORM, true}, // [38]
   {962,39+ADJ,10,10, CookieType::NORM, true}, // [39]
   {985,39+ADJ,10,10, CookieType::NORM, true}, // [40]

   {1008,39+ADJ,10,10, CookieType::NORM, true}, // [41]
   {1031,39+ADJ,10,10, CookieType::NORM, true}, // [42]
   {1058,39+ADJ,10,10, CookieType::NORM, true}, // [43]
   {1081,39+ADJ,10,10, CookieType::NORM, true}, // [44]
   {1104,39+ADJ,10,10, CookieType::NORM, true}, // [45]

   {1127,39+ADJ,10,10, CookieType::NORM, true}, // [46]
   {1150,39+ADJ,10,10, CookieType::NORM, true}, // [47]
   {1173,39+ADJ,10,10, CookieType::NORM, true}, // [48]
   {1202,39+ADJ,10,10, CookieType::NORM, true}, // [49]
   {1225,39+ADJ,10,10, CookieType::NORM, true}, // [50]

   {1248,39+ADJ,10,10, CookieType::NORM, true}, // [51]
   {1271,39+ADJ,10,10, CookieType::NORM, true}, // [52]
   {1294,39+ADJ,10,10, CookieType::NORM, true}, // [53]
   {1317,39+ADJ,10,10, CookieType::NORM, true}, // [54]
   {1346,39+ADJ,10,10, CookieType::NORM, true}, // [55]

   {1346,62+ADJ,10,10, CookieType::NORM, true}, // [56]
   {1336,72+ADJ,30,30, CookieType::POW, true},  // [57]
   {33,  64+ADJ,10,10, CookieType::NORM, true},   // [58]
   {23,  74+ADJ,30,30, CookieType::POW, true},    // [59]
   {33,  107+ADJ,10,10, CookieType::NORM, true},  // [60]

   {56,107+ADJ,10,10, CookieType::NORM, true},  // [61]
   {79,107+ADJ,10,10, CookieType::NORM, true},  // [62]
   {102,107+ADJ,10,10, CookieType::NORM, true}, // [63]
   {129,107+ADJ,10,10, CookieType::NORM, true}, // [64]
   {365,62+ADJ,10,10, CookieType::NORM, true},  // [65]

   {365,85+ADJ,10,10, CookieType::NORM, true},  // [66]
   {365,107+ADJ,10,10, CookieType::NORM, true}, // [67]
   {390,107+ADJ,10,10, CookieType::NORM, true}, // [68]
   {413,107+ADJ,10,10, CookieType::NORM, true}, // [69]
   {436,107+ADJ,10,10, CookieType::NORM, true}, // [70]

   {459,107+ADJ,10,10, CookieType::NORM, true}, // [71]
   {482,107+ADJ,10,10, CookieType::NORM, true}, // [72]
   {505,107+ADJ,10,10, CookieType::NORM, true}, // [73]
   {528,107+ADJ,10,10, CookieType::NORM, true}, // [74]
   {557,107+ADJ,10,10, CookieType::NORM, true}, // [75]

   {581,107+ADJ,10,10, CookieType::NORM, true}, // [76]
   {605,107+ADJ,10,10, CookieType::NORM, true}, // [77]
   {629,107+ADJ,10,10, CookieType::NORM, true}, // [78]
   {653,107+ADJ,10,10, CookieType::NORM, true}, // [79]
   {677,107+ADJ,10,10, CookieType::NORM, true}, // [80]

   {701,107+ADJ,10,10, CookieType::NORM, true}, // [81]
   {725,107+ADJ,10,10, CookieType::NORM, true}, // [82]
   {748,107+ADJ,10,10, CookieType::NORM, true}, // [83]
   {748,63+ADJ,10,10, CookieType::NORM, true},  // [84]
   {748,87+ADJ,10,10, CookieType::NORM, true},  // [85]

   {1058,63+ADJ,10,10, CookieType::NORM, true},  // [86]
   {1058,87+ADJ,10,10, CookieType::NORM, true},  // [87]
   {1058,107+ADJ,10,10, CookieType::NORM, true}, // [88]
   {1202,63+ADJ,10,10, CookieType::NORM, true},  // [89]
   {1202,87+ADJ,10,10, CookieType::NORM, true},  // [90]

   {1202,107+ADJ,10,10, CookieType::NORM, true}, // [91]
   {1269,107+ADJ,10,10, CookieType::NORM, true}, // [92]
   {1293,107+ADJ,10,10, CookieType::NORM, true}, // [93]
   {1317,107+ADJ,10,10, CookieType::NORM, true}, // [94]
   {1346,107+ADJ,10,10, CookieType::NORM, true}, // [95]

   {365,131+ADJ,10,10, CookieType::NORM, true}, // [96]
   {365,155+ADJ,10,10, CookieType::NORM, true}, // [97]
   {365,179+ADJ,10,10, CookieType::NORM, true}, // [98]
   {365,203+ADJ,10,10, CookieType::NORM, true}, // [99]
   {365,227+ADJ,10,10, CookieType::NORM, true}, // [100]

   {365,251+ADJ,10,10, CookieType::NORM, true}, // [101]
   {365,275+ADJ,10,10, CookieType::NORM, true}, // [102]
   {129,131+ADJ,10,10, CookieType::NORM, true}, // [103]
   {129,155+ADJ,10,10, CookieType::NORM, true}, // [104]
   {129,179+ADJ,10,10, CookieType::NORM, true}, // [105]

   {129,201+ADJ,10,10, CookieType::NORM, true},  // [106]
   {222,201+ADJ,10,10, CookieType::NORM, true},  // [107]
   {246,201+ADJ,10,10, CookieType::NORM, true},  // [108]
   {264,190+ADJ,30,30, CookieType::POW,  true},  // [109]
   {748,131+ADJ,10,10, CookieType::NORM, false}, // [110]

   {748,155+ADJ,10,10, CookieType::NORM, false}, // [111]
   {748,179+ADJ,10,10, CookieType::NORM, false}, // [112]
   {748,203+ADJ,10,10, CookieType::NORM, false}, // [113]
   {748,227+ADJ,10,10, CookieType::NORM, false}, // [114]
   {748,248+ADJ,10,10, CookieType::NORM, false}, // [115]

   {962,131+ADJ,10,10, CookieType::NORM, false}, // [116]
   {962,155+ADJ,10,10, CookieType::NORM, false}, // [117]
   {962,179+ADJ,10,10, CookieType::NORM, false}, // [118]
   {962,203+ADJ,10,10, CookieType::NORM, false}, // [119]
   {962,227+ADJ,10,10, CookieType::NORM, false}, // [120]

   {962,248+ADJ,10,10, CookieType::NORM, false}, // [121]
   {1152,226+ADJ,10,10, CookieType::NORM, true}, // [122]
   {1176,226+ADJ,10,10, CookieType::NORM, true}, // [123]
   {1200,226+ADJ,10,10, CookieType::NORM, true}, // [124]
   {1224,226+ADJ,10,10, CookieType::NORM, true}, // [125]

   {1245,226+ADJ,10,10, CookieType::NORM, true}, // [126]
   {1245,131+ADJ,10,10, CookieType::NORM, true}, // [127]
   {1245,155+ADJ,10,10, CookieType::NORM, true}, // [128]
   {1245,179+ADJ,10,10, CookieType::NORM, true}, // [129]
   {1245,202+ADJ,10,10, CookieType::NORM, true}, // [130]

   {32,297+ADJ,10,10, CookieType::NORM, true},  // [131]
   {56,297+ADJ,10,10, CookieType::NORM, true},  // [132]
   {80,297+ADJ,10,10, CookieType::NORM, true},  // [133]
   {104,297+ADJ,10,10, CookieType::NORM, true}, // [134]
   {129,225+ADJ,10,10, CookieType::NORM, true}, // [135]

   {129,249+ADJ,10,10, CookieType::NORM, true}, // [136]
   {129,273+ADJ,10,10, CookieType::NORM, true}, // [137]
   {129,297+ADJ,10,10, CookieType::NORM, true}, // [138]
   {365,297+ADJ,10,10, CookieType::NORM, true}, // [139]
   {389,297+ADJ,10,10, CookieType::NORM, true}, // [140]

   {413,297+ADJ,10,10, CookieType::NORM, true}, // [141]
   {413,321+ADJ,10,10, CookieType::NORM, true}, // [142]
   {413,345+ADJ,10,10, CookieType::NORM, true}, // [143]
   {486,297+ADJ,10,10, CookieType::NORM, true}, // [144]
   {486,321+ADJ,10,10, CookieType::NORM, true}, // [145]

   {486,345+ADJ,10,10, CookieType::NORM, true}, // [146]
   {510,297+ADJ,10,10, CookieType::NORM, true}, // [147]
   {534,297+ADJ,10,10, CookieType::NORM, true}, // [148]
   {557,297+ADJ,10,10, CookieType::NORM, true}, // [149]
   {174,297+ADJ,10,10, CookieType::NORM, true}, // [150]

   {198,297+ADJ,10,10, CookieType::NORM, true}, // [151]
   {222,297+ADJ,10,10, CookieType::NORM, true}, // [152]
   {246,297+ADJ,10,10, CookieType::NORM, true}, // [153]
   {270,297+ADJ,10,10, CookieType::NORM, true}, // [154]
   {294,297+ADJ,10,10, CookieType::NORM, true}, // [155]

   {318,297+ADJ,10,10, CookieType::NORM, true},  // [156]
   {342,297+ADJ,10,10, CookieType::NORM, true},  // [157]
   {962,273+ADJ,10,10, CookieType::NORM, false}, // [158]
   {962,297+ADJ,10,10, CookieType::NORM, true},  // [159]
   {1058,131+ADJ,10,10, CookieType::NORM, true}, // [160]

   {1058,155+ADJ,10,10, CookieType::NORM, true}, // [161]
   {1058,179+ADJ,10,10, CookieType::NORM, true}, // [162]
   {1058,203+ADJ,10,10, CookieType::NORM, true}, // [163]
   {1058,227+ADJ,10,10, CookieType::NORM, true}, // [164]
   {1058,251+ADJ,10,10, CookieType::NORM, true}, // [165]

   {1058,275+ADJ,10,10, CookieType::NORM, true}, // [166]
   {1058,297+ADJ,10,10, CookieType::NORM, true}, // [167]
   {1082,297+ADJ,10,10, CookieType::NORM, true}, // [168]
   {1106,297+ADJ,10,10, CookieType::NORM, true}, // [169]
   {1130,297+ADJ,10,10, CookieType::NORM, true}, // [170]

   {1154,297+ADJ,10,10, CookieType::NORM, true}, // [171]
   {1178,297+ADJ,10,10, CookieType::NORM, true}, // [172]
   {1201,297+ADJ,10,10, CookieType::NORM, true}, // [173]
   {1223,297+ADJ,10,10, CookieType::NORM, true}, // [174]
   {1245,297+ADJ,10,10, CookieType::NORM, true}, // [175]

   {1269,297+ADJ,10,10, CookieType::NORM, true}, // [176]
   {1293,297+ADJ,10,10, CookieType::NORM, true}, // [177]
   {1317,297+ADJ,10,10, CookieType::NORM, true}, // [178]
   {1343,297+ADJ,10,10, CookieType::NORM, true}, // [179]
   {32,321+ADJ,10,10, CookieType::NORM, true},   // [180]

   {21,333+ADJ,30,30, CookieType::POW, true},   // [181]
   {32,368+ADJ,10,10, CookieType::NORM, true},  // [182]
   {150,297+ADJ,10,10, CookieType::NORM, true}, // [183]
   {150,321+ADJ,10,10, CookieType::NORM, true}, // [184]
   {150,345+ADJ,10,10, CookieType::NORM, true}, // [185]

   {150,368+ADJ,10,10, CookieType::NORM, true}, // [186]
   {174,368+ADJ,10,10, CookieType::NORM, true}, // [187]
   {198,368+ADJ,10,10, CookieType::NORM, true}, // [188]
   {222,368+ADJ,10,10, CookieType::NORM, true}, // [189]
   {246,368+ADJ,10,10, CookieType::NORM, true}, // [190]

   {270,368+ADJ,10,10, CookieType::NORM, true}, // [191]
   {294,368+ADJ,10,10, CookieType::NORM, true}, // [192]
   {318,368+ADJ,10,10, CookieType::NORM, true}, // [193]
   {342,368+ADJ,10,10, CookieType::NORM, true}, // [194]
   {366,368+ADJ,10,10, CookieType::NORM, true}, // [195]

   {390,368+ADJ,10,10, CookieType::NORM, true}, // [196]
   {413,368+ADJ,10,10, CookieType::NORM, true}, // [197]
   {486,368+ADJ,10,10, CookieType::NORM, true}, // [198]
   {510,368+ADJ,10,10, CookieType::NORM, true}, // [199]
   {534,368+ADJ,10,10, CookieType::NORM, true}, // [200]

   {558,368+ADJ,10,10, CookieType::NORM, true}, // [201]
   {582,368+ADJ,10,10, CookieType::NORM, true}, // [202]
   {606,368+ADJ,10,10, CookieType::NORM, true}, // [203]
   {630,368+ADJ,10,10, CookieType::NORM, true}, // [204]
   {654,368+ADJ,10,10, CookieType::NORM, true}, // [205]

   {678,368+ADJ,10,10, CookieType::NORM, true}, // [206]
   {702,368+ADJ,10,10, CookieType::NORM, true}, // [207]
   {726,368+ADJ,10,10, CookieType::NORM, true}, // [208]
   {748,368+ADJ,10,10, CookieType::NORM, true}, // [209]
   {748,344+ADJ,10,10, CookieType::NORM, true}, // [210]

   {818,345+ADJ,10,10, CookieType::NORM, true}, // [211]
   {818,368+ADJ,10,10, CookieType::NORM, true}, // [212]
   {853,368+ADJ,10,10, CookieType::NORM, true}, // [213]
   {892,321+ADJ,10,10, CookieType::NORM, true}, // [214]
   {892,345+ADJ,10,10, CookieType::NORM, true}, // [215]

   {892,368+ADJ,10,10, CookieType::NORM, true}, // [216]
   {916,321+ADJ,10,10, CookieType::NORM, true}, // [217]
   {940,321+ADJ,10,10, CookieType::NORM, true}, // [218]
   {962,321+ADJ,10,10, CookieType::NORM, true}, // [219]
   {962,345+ADJ,10,10, CookieType::NORM, true}, // [220]

   {962,368+ADJ,10,10, CookieType::NORM, true},  // [221]
   {986,368+ADJ,10,10, CookieType::NORM, true},  // [222]
   {1010,368+ADJ,10,10, CookieType::NORM, true}, // [223]
   {1034,368+ADJ,10,10, CookieType::NORM, true}, // [224]
   {1058,368+ADJ,10,10, CookieType::NORM, true}, // [225]

   {1082,368+ADJ,10,10, CookieType::NORM, true}, // [226]
   {1106,368+ADJ,10,10, CookieType::NORM, true}, // [227]
   {1130,368+ADJ,10,10, CookieType::NORM, true}, // [228]
   {1154,368+ADJ,10,10, CookieType::NORM, true}, // [229]
   {1178,368+ADJ,10,10, CookieType::NORM, true}, // [230]

   {1201,368+ADJ,10,10, CookieType::NORM, true}, // [231]
   {1225,368+ADJ,10,10, CookieType::NORM, true}, // [232]
   {1249,368+ADJ,10,10, CookieType::NORM, true}, // [233]
   {1273,368+ADJ,10,10, CookieType::NORM, true}, // [234]
   {1297,368+ADJ,10,10, CookieType::NORM, true}, // [235]

   {1321,368+ADJ,10,10, CookieType::NORM, true}, // [236]
   {1343,368+ADJ,10,10, CookieType::NORM, true}, // [237]
   {1343,321+ADJ,10,10, CookieType::NORM, true}, // [238]
   {1333,333+ADJ,30,30, CookieType::POW, true},  // [239]
   {748,321+ADJ,10,10, CookieType::NORM, true},  // [240]

   {772,321+ADJ,10,10, CookieType::NORM, true},  // [241]
   {796,321+ADJ,10,10, CookieType::NORM, true},  // [242]
   {818,321+ADJ,10,10, CookieType::NORM, true},  // [243]
   {772,248+ADJ,10,10, CookieType::NORM, false}, // [244]
   {796,248+ADJ,10,10, CookieType::NORM, false}, // [245]

   {820,248+ADJ,10,10, CookieType::NORM, false}, // [246]
   {844,248+ADJ,10,10, CookieType::NORM, false}, // [247]
   {868,248+ADJ,10,10, CookieType::NORM, false}, // [248]
   {892,248+ADJ,10,10, CookieType::NORM, false}, // [249]
   {916,248+ADJ,10,10, CookieType::NORM, false}, // [250]

   {940,248+ADJ,10,10, CookieType::NORM, false}, // [251]
   {1225,107+ADJ,10,10, CookieType::NORM, true}, // [252]
   {1245,107+ADJ,10,10, CookieType::NORM, true}, // [253]
   {1082,107+ADJ,10,10, CookieType::NORM, true}, // [254]
   {1106,107+ADJ,10,10, CookieType::NORM, true}, // [255]

   {1130,107+ADJ,10,10, CookieType::NORM, true}, // [256]
   {1154,107+ADJ,10,10, CookieType::NORM, true}, // [257]
   {1178,107+ADJ,10,10, CookieType::NORM, true}, // [258]
   {962,63+ADJ,10,10, CookieType::NORM, false},   // [259]
   {962,87+ADJ,10,10, CookieType::NORM, false},   // [260]

   {854,107+ADJ,10,10, CookieType::NORM, false}, // [261]
   {772,107+ADJ,10,10, CookieType::NORM, false}, // [262]
   {796,107+ADJ,10,10, CookieType::NORM, false}, // [263]
   {820,107+ADJ,10,10, CookieType::NORM, false}, // [264]
   {887,107+ADJ,10,10, CookieType::NORM, false}, // [265]

   {910,107+ADJ,10,10, CookieType::NORM, false}, // [266]
   {933,107+ADJ,10,10, CookieType::NORM, false}, // [267]
   {557,131+ADJ,10,10, CookieType::NORM, true},  // [268]
   {557,155+ADJ,10,10, CookieType::NORM, true},  // [269]
   {557,179+ADJ,10,10, CookieType::NORM, true},  // [270]

   {557,203+ADJ,10,10, CookieType::NORM, true}, // [271]
   {557,227+ADJ,10,10, CookieType::NORM, true}, // [272]
   {557,251+ADJ,10,10, CookieType::NORM, true}, // [273]
   {557,275+ADJ,10,10, CookieType::NORM, true}, // [274]
   {581,297+ADJ,10,10, CookieType::NORM, true}, // [275]

   {605,297+ADJ,10,10, CookieType::NORM, true}, // [276]
   {629,297+ADJ,10,10, CookieType::NORM, true}, // [277]
   {653,297+ADJ,10,10, CookieType::NORM, true}, // [278]
   {677,297+ADJ,10,10, CookieType::NORM, true}, // [279]
   {701,297+ADJ,10,10, CookieType::NORM, true}, // [280]

   {725,297+ADJ,10,10, CookieType::NORM, true},  // [281]
   {748,273+ADJ,10,10, CookieType::NORM, false},  // [282]
   {748,297+ADJ,10,10, CookieType::NORM, true},  // [283]
   {986,297+ADJ,10,10, CookieType::NORM, true},  // [284]
   {1010,297+ADJ,10,10, CookieType::NORM, true}, // [285]

   {1034,297+ADJ,10,10, CookieType::NORM, true}, // [286]
   {56,  368+ADJ,10,10, CookieType::NORM, true},   // [287]
   {80,  368+ADJ,10,10, CookieType::NORM, true},   // [288]
   {104, 368+ADJ,10,10, CookieType::NORM, true},  // [289]
   {128, 368+ADJ,10,10, CookieType::NORM, true},  // [290]

   {222,131+ADJ,10,10, CookieType::NORM, true}, // [291]
   {246,131+ADJ,10,10, CookieType::NORM, true}, // [292]
   {270,131+ADJ,10,10, CookieType::NORM, true}, // [293]
   {294,131+ADJ,10,10, CookieType::NORM, true}, // [294]
   {318,131+ADJ,10,10, CookieType::NORM, true}, // [295]

   {342,131+ADJ,10,10, CookieType::NORM, true}, // [296]
   {222,155+ADJ,10,10, CookieType::NORM, true}, // [297]
   {222,179+ADJ,10,10, CookieType::NORM, true}, // [298]
   {129,64+ADJ,10,10, CookieType::NORM, true},  // [299]
   {129,87+ADJ,10,10, CookieType::NORM, true},  // [300]

   {437,297+ADJ,10,10, CookieType::NORM, true},  // [301]
   {461,297+ADJ,10,10, CookieType::NORM, true},  // [302]
   {-14,201+ADJ,10,10, CookieType::NORM, false}, // [303]
   {9,201+ADJ,10,10, CookieType::NORM,   false}, // [304]
   {33,201+ADJ,10,10, CookieType::NORM,  false}, // [305]

   {56,201+ADJ,10,10, CookieType::NORM, false},   // [306]
   {79,201+ADJ,10,10, CookieType::NORM, false},   // [307]
   {1269,202+ADJ,10,10, CookieType::NORM, false}, // [308]
   {1293,202+ADJ,10,10, CookieType::NORM, false}, // [309]
   {1317,202+ADJ,10,10, CookieType::NORM, false}, // [310]

   {1341,202+ADJ,10,10, CookieType::NORM, false}, // [311]
   {1365,202+ADJ,10,10, CookieType::NORM, false}, // [312]
   {1245,250+ADJ,10,10, CookieType::NORM, true},  // [313]
   {1245,274+ADJ,10,10, CookieType::NORM, true},  // [314]
   {1201,321+ADJ,10,10, CookieType::NORM, true},  // [315]

   {1201,345+ADJ,10,10, CookieType::NORM, true},  // [316]
   {803,184+ADJ,10,10, CookieType::NORM,  false}, // [317]
   {854,184+ADJ,10,10, CookieType::NORM,  false}, // [318]
   {904,184+ADJ,10,10, CookieType::NORM,  false}, // [319]
   {962,107+ADJ,10,10, CookieType::NORM,  false}, // [320]

   {102,201+ADJ,10,10, CookieType::NORM, false}, // [321]
   {0,  0+ADJ,  0, 0,  CookieType::NORM, false}  // [322] INVALID
};



//////////////////////
// SceneContainer:: //
//////////////////////


// copy the contents of the `other` to `*this`.
SceneContainer& SceneContainer::operator=(const SceneContainer& other) {
 sceneList = other.sceneList;
 curScene  = other.curScene;
 curFrame  = other.curFrame;
 return *this;
}



// move the contents of the `other` to `*this`.
SceneContainer& SceneContainer::operator=(SceneContainer&& other) {
 sceneList = std::move(other.sceneList);
 curScene  = other.curScene;
 curFrame  = other.curFrame;
 return *this;
}



// remove the scene of `*this` identified by `sceneID`.
bool SceneContainer::RemoveScene(UINT sceneID) {
  if(sceneID < sceneList.size() ) {
    sceneList.erase(sceneList.begin() + sceneID);
    return true;
  }
  return false;
}



// select the desired scene.
bool SceneContainer::SelectScene(UINT sceneID) {
  if(sceneID < sceneList.size() ) {
     const Scene& newScene = sceneList[sceneID];

     curScene = sceneID;
     curFrame = (curFrame < newScene.totalFrame) ? (curFrame) : (0);

     sx       = newScene.contents[curFrame].sx;
     sy       = newScene.contents[curFrame].sy;
     sWidth   = newScene.contents[curFrame].sWidth;
     sHeight  = newScene.contents[curFrame].sHeight;
     return true;
  }
  return false;
}



// select the desired frame.
bool SceneContainer::SelectFrame(UINT nFrame) {
  if(curScene < sceneList.size() && curFrame != nFrame) {
    const Scene& scene = sceneList[curScene];

    curFrame = (nFrame < scene.totalFrame) ? (nFrame) : (0);
    sx       = scene.contents[curFrame].sx;
    sy       = scene.contents[curFrame].sy;
    sWidth   = scene.contents[curFrame].sWidth;
    sHeight  = scene.contents[curFrame].sHeight;

    return true;
  }
  return false;
}



// update the current frame to the next.
// you must have called to `SelectScene` or `SelectFrame` before.
void SceneContainer::NextFrame() {
  const auto& scene = sceneList[curScene];

  if(++curFrame >= scene.totalFrame) {
     curFrame = 0;
  }

  sx       = scene.contents[curFrame].sx;
  sy       = scene.contents[curFrame].sy;
  sWidth   = scene.contents[curFrame].sWidth;
  sHeight  = scene.contents[curFrame].sHeight;
}





//////////////////////
// GameObject::     //
//////////////////////


// copy constructor.
GameObject::GameObject(const GameObject& other) : SceneContainer(other) {
  src   = other.src;
  dest  = other.dest;
  curDir = other.curDir;
  speed = other.speed;
}


// move constructor.
GameObject::GameObject(GameObject&& other) : SceneContainer(std::move(other) ) {
  src   = other.src;
  dest  = other.dest;
  curDir = other.curDir;
  speed = other.speed;

  other.src  = &Node::map[INVALID];
  other.dest = &Node::map[INVALID];
  other.curDir      = DIR::NONE;
  speed      = 0;
}



// update `*this` position.
void GameObject::UpdatePosition(DIR dir) {

 switch(dir) {
   case DIR::UP: {
        if((dy -= speed) <= dest->dy) {
           const auto nextID = dest->adjacent[(UINT) DIR::UP].nodeID;
           dy   = dest->dy;
           src  = dest;
           dest = &Node::map[nextID];
        }
        break;
   }
   case DIR::RIGHT: {
        if((dx += speed) >= dest->dx) {
           const auto nextID = dest->adjacent[(UINT) DIR::RIGHT].nodeID;
           dx   = dest->dx;
           src  = dest;
           dest = &Node::map[nextID];
        }
        break;
   }
   case DIR::DOWN: {
        if((dy += speed) >= dest->dy) {
           const auto nextID = dest->adjacent[(UINT) DIR::DOWN].nodeID;
           dy   = dest->dy;
           src  = dest;
           dest = &Node::map[nextID];
        }
        break;
   }
   case DIR::LEFT: {
        if((dx -= speed) <= dest->dx) {
           const auto nextID = dest->adjacent[(UINT) DIR::LEFT].nodeID;
           dx   = dest->dx;
           src  = dest;
           dest = &Node::map[nextID];
        }
        break;
   }
 };
}



// check if `*this` is collided with `inObject`.
bool GameObject::HitTest(const GameObject& inObject) const {
  const UINT distX = abs(dx - inObject.dx);
  const UINT distY = abs(dy - inObject.dy);

  if( (distX * distX) + (distY * distY) <= 576) {
     return true;
  }
  return false;
}




// set the source node, destination node, and the direction.
bool GameObject::SetPosition(UINT srcID, DIR inDir) {
  if(srcID != INVALID) {
    src    = &Node::map[srcID];
    dest   = &Node::map[src->adjacent[(UINT) inDir].nodeID];
    curDir = inDir;
    dx     = src->dx;
    dy     = src->dy;
    return true;
  }
  return false;
}














