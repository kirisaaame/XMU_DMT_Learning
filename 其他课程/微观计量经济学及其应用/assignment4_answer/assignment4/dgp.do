cd "D:/Users/user/Dropbox/MEONLY/xiamen/Course/applied micro/24-25Xiangan/assignments/assignment4"

clear
set obs 1000
gen censusblock = _n
gen lat = runiform(9.7, 9.8)
gen lon = runiform(-84.1, -83.7)
gen censuserror = rnormal(0, 0.1)
expand 10
gen UFCo =  (lat < 9.76 & lat >9.73 & lon< -83.6 & lon> -84)
gen slope = runiform(-0.02, 0.02) + UFCo* runiform(0, 0.01)
gen slope2 = slope^2
gen housing = UFCo* (-0.102) + slope*0.7 -1*slope2 + 1*lat - 0.03*lon + rnormal(0,0.1) + censuserror
drop censuserror slope2
sa Astua_Pirie_HH, replace