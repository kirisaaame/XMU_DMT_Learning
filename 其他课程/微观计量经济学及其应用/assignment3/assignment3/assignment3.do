/* -------------------------------------------------------------------------- */
/* ------------------------  Applied Econometrics  -------------------------- */
/* ------------------------   Assignment 3         -------------------------- */
/* ------------------------       11/20/2024       -------------------------- */
/* -------------------------------------------------------------------------- */

clear	
capture log close 
log using ./assignment3.log, replace
use "HunanCntyYr.dta",clear
/******************************************************************************/
/* Consider the paper "Web of Power" by Bai et al. They try to analyze how elite networks influence soldiers' death during Taiping movement (1851-1864). Elite network is captured by Zeng Guofan's personal network based mainly on his connections via kinship or civil service examination. 
Data: HunanCntyYr.dta
Key variables: 
- The number of soldier death: martyr
- define the post-treatment indicator: Hunan Army joined the Taiping movement in 1854, so years after 1854 are the post-treatment years
- connection density: Zeng_all0_invdist
- countyid: cntyid
- year: year
*/
/******************************************************************************/

/*Q1: Take Hunan counties with connection density above average as the treatment group, and those in Hunan with less-than-average connection density with Zeng as control. Please replicate Figure 3 with dependent variable being the the number of soldier death. 
*/
/* -------------------------------------------------------------------------- */
/*A10: */
preserve
summarize Zeng_all0_invdist
local avg_density = r(mean)

/* Define treatment and control groups */
gen treatment = (Zeng_all0_invdist > `avg_density')

/* Post-treatment indicator */
gen post = (year > 1854)

/* Create interaction term for DiD */
gen interaction = treatment * post

/* Q1: Calculate average soldier deaths for each group by year */
collapse (mean) avg_martyr = martyr, by(year treatment)

/* Plotting average soldier deaths */
twoway (line avg_martyr year if treatment == 1, mcolor(red) lcolor(red) msymbol(O)) ///
       (line avg_martyr year if treatment == 0, mcolor(blue) lcolor(blue) msymbol(X)) ///
       , legend(label(1 "Treatment") label(2 "Control")) ///
       title("Average Soldier Deaths by Treatment Group") ///
       xtitle("Year") ytitle("Average Number of Soldier Deaths")
restore
/* -------------------------------------------------------------------------- */

/*Q2: Following the definition of treatment and control group in Q1, please implement a DiD to estimate ATET. 
 */
/* -------------------------------------------------------------------------- */
/*A11: */
/* -------------------------------------------------------------------------- */
/* DiD estimation */
reg martyr treatment post interaction, robust cluster(cntyid)

/* Output the results */
estimates table, b(%9.3f) se(%9.3f) starlevels(0.01 0.05 0.1)
/*Q3: Now we replicate Table 2 of their paper by implementing a continuous DiD scheme. Instead of defining two groups - the treatment and the control - we now directly use the connection density (Zeng_all0_invdist) as the definition of treatment. When connection density is 0, a county is not treated. As connection density increases, the treatment intensity also increases. They include county fixed effects, year fixed effects, and cluster standard errors at county level. */
/* -------------------------------------------------------------------------- */
/*A12: */
/* -------------------------------------------------------------------------- */
/* Continuous DiD using connection density */
reg martyr Zeng_all0_invdist post i.cntyid i.year, robust cluster(cntyid)

/* Output the results */
estimates table, b(%9.3f) se(%9.3f) starlevels(0.01 0.05 0.1)