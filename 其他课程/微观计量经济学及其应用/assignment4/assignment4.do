/* -------------------------------------------------------------------------- */
/* ------------------------  Applied Econometrics  -------------------------- */
/* ------------------------   Assignment 4         -------------------------- */
/* ------------------------       12/14/2024       -------------------------- */
/* -------------------------------------------------------------------------- */

clear	
capture log close 
cd ""
log using assignment4.log, replace
/******************************************************************************/
/* Consider the paper - MULTINATIONALS, MONOPSONY, AND LOCAL DEVELOPMENT. 
Data: Astua_Pirie_HH.dta
Key variables: 
- censusblock: the geographic unit
- housing: the number of unsatisified basic needs in housing
- slope
- lon, lat: longitude and attitute
- UFCo: the dummy variable that indicate if the census block is within the concession of the united fruit company
*/
/******************************************************************************/

/*Q1: Please implement an RD analysis. 
Hint: 1. this is a SHARP RD!
      2. please cluster at censusblock level
	  3. please implement a parametric estimation. You are free to choose what f() to use. 
*/
/* -------------------------------------------------------------------------- */
/*A10: please write your code below. Please cluster at census block level */
/* -------------------------------------------------------------------------- */
*Load dataset
use "Astua_Pirie_HH.dta", clear


/*Q2: Suppose that people within the concession NOT mean that the person lives in the concession long enough to get treated - they may just moved in recently. To accurately make causal inference, we should implement a fuzzy RD. 
Now suppose the whether a person gets treated is denoted as "treat". Note that in a sharp RD setting, treat = UFCo. 
 */
/* -------------------------------------------------------------------------- */
/*A11: Please write your code here: */
/* -------------------------------------------------------------------------- */


	
/*Q3: What control variables do you include? Why do you include them? */
/* -------------------------------------------------------------------------- */
/*A12: */
/* -------------------------------------------------------------------------- */


/*Q4: Professor Smart: housing facitilies also depend on the slope. Steep places are also hard to do any constructions. Moreover, the slope is correlated with UFCo, because the company must have wisely chosen the concession to suitably plant bananas. Therefore, we should include slope, as well as the squared slope, as controls. Do you agree? Please implement this regression. */
/* -------------------------------------------------------------------------- */
/*A12: */
/* -------------------------------------------------------------------------- */


