/* -------------------------------------------------------------------------- */
/* ------------------------  Applied Econometrics  -------------------------- */
/* ------------------------   Assignment 2         -------------------------- */
/* ---------------------------       10/7/2024        ----------------------- */
/* -------------------------------------------------------------------------- */

clear	
capture log close 
cd ""
log using assignment2.log, replace

use foxpersuasion, clear
/******************************************************************************/
/*Name: Zou Jifan*/
/*Student ID: 37220222203904*/
/******************************************************************************/

/******************************************************************************/
/* PART III: INSTRUMENTAL VARIABLE              */
/* Suppose you want to analyze the persuasion effect of media on audience. You collect American audience-level data on their daily length of media exposure to two popular media channels: CNN and FOX news. The former is a left-wing media and the latter is right-wing. Regarding audience's attitude: they examine if they are more liberal (left) or conservative (right). 
- Dataset: foxpersuasion.dta 
- Key variables: 
-- right: indicator of whether the audience is left- or right- wing
-- viewfox: number of hours viewing fox 
-- foxrank: the rank of fox channels
-- mountainous: the strength of signal due to geographical features
-- eprice: price of electricity
*/

/*Q1: Now three students propose three instrumental variables: 
- Student A: the rank of channels (foxrank). Imagine that tv automatically opens Channel 1 when you turn it on. The more upfront the channel is, the more likely an audience will view it. 
- Student B: the geographical features that affect satellite signals (mountainous). One proxy could be how mountainous a region is. 
- Student C: the price of electricity (eprice). The more expensive electricity is, the less likely they will watch tv. 
Please pick one of your favoriate and run an iv regression. */
/* -------------------------------------------------------------------------- */
/*A1:
*/
* Load the dataset
use "foxpersuasion.dta", clear

* IV regression using foxrank as the instrument for viewfox
ivregress 2sls right (viewfox = foxrank) mountainous eprice

* Note: right is the dependent variable, viewfox is the endogenous variable,
* and foxrank is the instrument.

/*Q2: Please run an OLS regression and answer the questions: does the OLS estimate look different from the IV estimate? If yes then why? */
/* -------------------------------------------------------------------------- */
/*A2: 
 */
* OLS regression
regress right viewfox mountainous eprice

* Compare results with the IV regression.

/*Q3: Is your picked iv relevant? Why */
/* -------------------------------------------------------------------------- */
/*A3:  it is relevant because it is correlated with the endogenous variable "viewfox." Since channels ranked higher are more likely to be viewed, this relationship should support its relevance. You can check the first-stage F-statistic for further confirmation.*/
/* -------------------------------------------------------------------------- */


log close 