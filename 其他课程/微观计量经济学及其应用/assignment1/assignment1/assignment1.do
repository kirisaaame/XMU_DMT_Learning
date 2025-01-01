/* -------------------------------------------------------------------------- */
/* ------------------------  Applied Econometrics  -------------------------- */
/* ------------------------  Midterm Examination   -------------------------- */
/* ---------------------------       11/17/2023       ----------------------- */
/* -------------------------------------------------------------------------- */

clear	
capture log close 
cd ""
log using assignment1.log, replace

/******************************************************************************/
/*Name: Zou Jifan*/*/
/*Student ID: 37220222203904*/
/******************************************************************************/

/******************************************************************************/
/* PART I: RANDOMIZED CONTROLLED TRIALS AND QUASI EXPERIMENTS      */
/* Suppose we want to analyze the effect of early childhood education on social preferences, mainly, people's preferences on fairness and efficiency. Early childhood education can be undertaken as a full-time pre-school or a stay-home parental education.  
- Dataset: data_JPE_2019_deidentified.dta
- Key variables: 
-- inequalityefficiency captures how much they value efficiency over equality. 
-- inequalitylucky captures how much they allow inequality due to luck. 
-- inequalitymerit: how much they allow inquality due to merits 
-- inequalitydictator: how much they allow inequality when they are distributing among themselves and others (i.e., when their interests are involved. )
-- any_PA: parental program 
-- any_PK: preschool education
 */
/******************************************************************************/

/* -------------------------------------------------------------------------- */
/*Q1: Suppose we collect observational data, which consists of a number of children who either received stay-home parental education or full-time pre-school education before they are 6 years old. Suppose that this observational data include a survey of children about their social preferences after they grow up. Can we use this data to conduct a simple comparison and conclude the differences in social preferences as a causal effect by early education style? */
/* -------------------------------------------------------------------------- */
/*A1: */
/* -------------------------------------------------------------------------- */

/*Q2: Suppose we adopt the idea of student B and C and decide to design three groups. Suppose the randomization is perfectly designed and implemented such that it is double-blind and random. The data is given by data1.dta. Now, please estimate the ATE of parental education and pre-school education.  */
/* -------------------------------------------------------------------------- */
/*A5: (type your code below) */

/* -------------------------------------------------------------------------- */

/*Q3: Given your results and a significance level alpha = 0.1, can you reject the hypothesis that attending preschool has no effect on social preferences? Can you reject the hypothesis that parental education has no effect on social preferences? Why? What if the significance level alpha is given as 0.05. HINT: Check the following variables: inequalityefficiency and inequalitylucky. */
/* -------------------------------------------------------------------------- */
/*A6:  */
/* -------------------------------------------------------------------------- */


/*Q4: How would you interpret your results? Specifically, what do you think is(are) the mechanism(s) behind that drive the current results? Please propose one additional test to confirm or rule out a mechanism. 
HINT: You are more than welcome to check other measures of social preferences. */
/* -------------------------------------------------------------------------- */
/*A7:  */
/* -------------------------------------------------------------------------- */


log close 