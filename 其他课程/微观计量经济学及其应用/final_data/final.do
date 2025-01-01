use "C:\Users\kirisaaame\Downloads\final_data\final_data\HunanCntyYr.dta"

* Generate log of soldier deaths
gen log_martyr = log(martyr + 1)

* Identify treatment and control groups
gen treatment = (Zeng_allO_invdist >= mean(Zeng_allO_invdist))

* Parallel Trend Analysis
reghdfe log_martyr i.year##c.treatment, absorb(cntyid) cluster(cntyid)
margins, dydx(treatment) at(year=_all)
marginsplot, title("Parallel Trend Analysis") ///
    xlabel(1851(1)1864) ylabel(-0.5(0.1)0.5) ///
    scheme(s1color) graphregion(color(white))
graph export "parallel_trend.png", replace