# Distribution Functions
Console applicationes for distribution functions implemented in `FunktionWin` (see Schrausser, 2011, 2023a, res.).
Theta applications 
generating distributions and estimators for several parameters $\theta$ within different designs via *bootstrap* method, with given number of resamples $B$, where bootstrap estimator

$$\hat\theta_B=B^{-1}⋅\sum_{i=1}^B\theta^*_i.$$

Implemented in `ThetaWin` (see Schrausser, 2009, 2023b, res.).

## Binomial

$$f(X\le k|n)=\sum_{i=0}^k{\frac{n!}{i!⋅(n-i)!}}⋅p^i⋅q^{(n-i)}.$$

Usage: 

     Binomial [p] [k] [n] [[1]]
     [p] ............. probability of event A
     [k] ............. n of events A
     [n] ..............n of trials
     [1] ............. (1) full output

## Binomial_T

$$f(X\le b|b,c)=p=\sum_{i=0}^b{\frac{(b+c)!}{i!⋅(b+c-i)!}}⋅2^{-i}⋅2^{-(b+c-i)}.$$

Usage: 

     Binomial_T [b] [c] [[1]]
     [b] ............. cell count b
     [c] ............. cell count c
     [1] ............. (1) full output

## epsilon

$$\varepsilon=\frac{\mu_1-\mu_0}{\hat\sigma}.$$

Usage: 

     epsilon [mode] [Q0] [s] [n] [e|Q1] [p] [df] [[x]]
     [mode] .......... (1)Effect-size (2)Theta.1
     [Q0] .............Theta.0
     [s] ............. Standard deviation
     [n] ............. n of cases
     [e|Q1] .......... Epsilon | Theta.1
     [p] ............. Percent-level (0.00)
     [df] ............ Degrees of freedom n - (.)
     [x] ............. Test value

## F_Function

$$F(F,df_1, df_2)=1-p^{\alpha 2}= \int\limits_0^F \frac{\mathit{\Gamma} _{(\frac{df_1+df_2}{2})}}{\mathit{\Gamma} _{(\frac{df_1}{2})} ⋅\mathit{\Gamma} _{(\frac{df_2}{2})}} ⋅\Bigl(\frac{df_1}{df_2}\Bigr)^{\frac{df_1}{2}} ⋅F^{\frac{df_1}{2}-1} ⋅\Bigl(1+\frac{df_1}{df_2} ⋅F\Bigr)^{-\frac{df_1+df_2}{2}} \ dF.$$

Usage:
 
      F_Function [mode] [x] [n1] [n2]
      [mode] ......... (1)Fx=p->F (2)Fy=F->p
      [x] ............ p-Wert/F-Wert
      [n1] ........... n1
      [n2] ........... n2

## Fisher_Exact

$$f(X=a|a,b,c,d)=P0=\frac{(a+b)!⋅(c+d)!⋅(a+c)!⋅(b+d)!}{(a+b+c+d)!⋅a!⋅b!⋅c!⋅d!},$$

$$f(X\le n|a,b,c,d)=p^{exact2}=\sum\limits_{i=0}^n Pi;\ Pi\le P0.$$

Usage: 

      Fisher_Exact [a] [b] [c] [d] [[1]]
      [a][b][c][d] ... cell counts a,b,c,d
      [1] ............ (1) full output

## Fisher_Z

$$Z=\frac{1}{2}⋅\mathrm{log_e}\Bigl(\frac{1+r}{1-r}\Bigr),$$

$$r=\frac{\mathrm{e}^{2⋅Z}-1}{\mathrm{e}^{2⋅Z}+1}.$$

Usage: 

      Fisher_Z [mode] [x]
      [mode] ......... (1)r->Z (2)Z->r
      [x] ............ r-value/Z-value

## GAMMA_Function

$$f(x,t)=\mathit{\Gamma} = \int\limits_0^\infty {t^{x-1} } ⋅\mathrm{e}^{-t} \ dt+c.$$

Usage: 

      GAMMA_Function [mode] [value]
      [mode] ......... (1)F(x)->⌈ (2)F'(⌈)->x
      [value] ........ x / ⌈

## GAMMA

Usage: 
 
      GAMMA [n] [input] [output]
      [n] ............ n of cases
      [input] ........ input file
      [output] ....... output file

## Geometric

$$f(X\le r|p)=\sum_{i=0}^r{p⋅q^i}.$$

Usage: 

      Geometric [p] [r+1] [[1]]
      [p] ............ probability of event A
      [r+1] .......... n of trials
      [1] ............ (1) full output

## Hypergeometric

$$f(X\le k|n,K,N)=\sum_{i=0}^k{\frac{\binom{K}{i}⋅\binom{N-K}{n-i}}{\binom{N}{n}}}.$$

Usage: 

      Hypergeometric [k] [n] [N] [K] [[1]]
      [k] ............ n of events A in Sub-Population
      [n] ............ size of Sub-Population
      [N] ............ size of Population
      [K] ............ n of events A in Population
      [1] ............ (1) full output


## Poisson

$$f(X\le k|n,p)=\sum_{i=0}^k\frac{(n⋅p)^i}{\mathrm{e}^{n⋅p}⋅i!}.$$

Usage:

      Poisson [p] [k] [n] [[1]]
      [p] ............ probability of event A
      [k] ............ n of events A
      [n] ............ n of trials
      [1] ............ (1) full output

## t_Function

$$F(t,df)=p=\int\limits_{-\infty}^t\frac{\mathit{\Gamma} _{(\frac{df-1}{2})}}{\mathit{\Gamma} _{(\frac{df}{2})}}⋅(df⋅\mathrm{\pi})^{-\frac{1}{2}}⋅\Bigl(1+\frac{t^2}{df}\Bigr)^{-\frac{df-1}{2}}\ dt.$$

Usage:

      t_Function [mode] [x] [n]
      [mode] ......... (1)Fx=p->t (2)Fy=t->p
      [x] ............ p-value/t-value
      [n] ............ n of cases

## x2_Function

$$F(\chi^2,df)=1-p^{\alpha 2}= \int\limits_0^{\chi^2} \frac{1}{2^{\frac{df}{2}}⋅\mathit{\Gamma} _{(\frac{df}{2})}} ⋅(\chi^2)^{\frac{df}{2}-1} ⋅\mathrm{e}^{-\frac{\chi^2}{2}}\ d\chi^2.$$

Usage: 

      x2_Function [mode] [x] [n]
      [mode] ......... (1)Fx=p->x² (2)Fy=x²->p
      [x] ............ p-value/x²-value
      [n] ............ n of cases

## z_Dichte

$$f(z) =\vartheta= \frac{1}{{\sqrt {2⋅\mathrm{\pi}} }}⋅\mathrm{e}^{-\frac{z^2}{2}},$$

$$f^{-1}(z)=f(\vartheta)=z= \sqrt{\ln\Biggl(\frac{\vartheta}{\sqrt{(2⋅ \mathrm{\pi} )^{-1}}}\Biggr)^{-2}},$$

$$F(z)=p=\int\limits_{-\infty}^z\vartheta \ dz.$$

Usage: 

      z_Dichte [modus] [wert] [[f]]
      [modus] ........ (1)fx=z->d (2)fy=d->z (3) ∫x=z->p
                       (4) ∫'p->z (5) ∫'p->d (6) ∫y=d->p
      [wert] ......... z-Wert/z-Dichte/Prozentrang p
      [f] ............ (1)z-Dichte Funktionsgraph

## z_Function

Usage: 

      z_Function [mode] [x]
      [mode] ......... (1)Fx=p->z (2)Fy=z->p
      [x] ............ p-value/z-value


## Theta

Usage: 

    Theta [sd] [min] [max] [qq] [q] [v] [s] [[x]] [[g]]
     [sd]  ........... Seed: |0| Zeitwert
     [min] ........... R Minimalwert
     [max] ........... R Maximalwert
     [qq]  ........... Theta-Theta/
     [q]   ........... Theta:
                       |0| Harmonisches Mittel (HM)
                       |1| Arithmetisches Mittel (AM)
                       |2| Summe (SUM)
                       |3| Standardabweichung (SD)
                       |4| Populationsvarianzschaetzung (VAR)
                       |5| Produktsumme(PSM)
                       |6| Geometrisches Mittel(GM)
                       |7| Schrausser's d (D)
                       |8| DvarO (DV)
     [v]  ...........  n zu Theta (v)
     [s]  ...........  n Subpopulationen (s)
     [x]  ...........  Vergleichswert x
     [g]  ...........  |1| Wertebereich ganzzahlig

## Theta Q

Usage: 

     Theta_Q [sd][min][max][qq][qp][qs1][qs2][qQ][v][m][n][s] [[x]] [[g]]
     [sd]  ........................... Seed: |0| Zeitwert
     [min] ........................... R Minimalwert
     [max] ........................... R Maximalwert
     [qq]  ........................... Theta-Theta/
     [qp]  ........................... Theta P/
     [qs1] [qs2] ..................... Theta S1, S2:
                                       |0| Harmonisches Mittel (HM)
                                       |1| Arithmetisches Mittel (AM)
                                       |2| Summe (SUM)
                                       |3| Standardabweichung (SD)
                                       |4| Populationsvarianzschaetzung (VAR)
                                       |5| Produktsumme(PSM)
                                       |6| Geometrisches Mittel(GM)
                                       |7| Schrausser's d (D)
                                       |8| DvarO (DV)
     [qQ]  ........................... Theta Q:
                                       |1| Differenz
                                       |2| Quotient
                                       |3| Summe
                                       |4| Produkt
     [v]  ...........................  n zu Theta P (v)
     [m]  ...........................  n zu Theta S1 (m)
     [n]  ...........................  n zu Theta S2 (n)
     [s]  ...........................  n Subpopulationen (s)
     [x]  ...........................  Vergleichswert x
     [g]  ...........................  |1| Wertebereich ganzzahlig

## Theta Qv

Usage: 

    Theta_Qv [sd][min][max][qq][qp][qs1][qs2][qQ][QQ][v][n][s] [[x]] [[g]]
     [sd]  ........................... Seed: |0| Zeitwert
     [min] ........................... R Minimalwert
     [max] ........................... R Maximalwert
     [qq]  ........................... Theta-Theta/
     [qp]  ........................... Theta P/
     [qs1][qs2]....................... Theta S1, S2/
     [qQ]  ........................... Theta Q:
                                       |0| Harmonisches Mittel (HM)
                                       |1| Arithmetisches Mittel (AM)
                                       |2| Summe (SUM)
                                       |3| Standardabweichung (SD)
                                       |4| Populationsvarianzschaetzung (VAR)
                                       |5| Produktsumme(PSM)
                                       |6| Geometrisches Mittel(GM)
                                       |7| Schrausser's d (D)
                                       |8| DvarO (DV)
     [QQ]  ........................... Theta Theta Q:
                                       |1| Differenz
                                       |2| Quotient
                                       |3| Summe
                                       |4| Produkt
                                       |5| Korrelation
                                       |6| Kovarianz
                                       |7| Determinationskoeffizient
                                       |8| Redundanz
     [v]  ...........................  n zu Theta P (v)
     [n]  ...........................  n zu Theta S1,S2 (n)
     [s]  ...........................  n Subpopulationen (s)
     [x]  ...........................  Vergleichswert x
     [g]  ...........................  |1| Wertebereich ganzzahlig

## Theta rQ

Usage: 

     Theta_rQ [sd][min][max][qq][qp][q11][q12][q21][q22][qr1][qr2][qQ][v][m][n][s] [[x]] [[g]]
     [sd]  ....................... Seed: |0| Zeitwert
     [min] ....................... R Minimalwert
     [max] ....................... R Maximalwert
     [qq]  ....................... Theta-Theta/
     [qp]  ....................... Theta P/
     [q11][q12] .................. Theta S11, S12/
     [q21][q22] .................. Theta S21, S22:
                                   |0| Harmonisches Mittel (HM)
                                   |1| Arithmetisches Mittel (AM)
                                   |2| Summe (SUM)
                                   |3| Standardabweichung (SD)
                                   |4| Populationsvarianzschaetzung (VAR)
                                   |5| Produktsumme(PSM)
                                   |6| Geometrisches Mittel(GM)
                                   |7| Schrausser's d (D)
                                   |8| DvarO (DV)
     [qr1][qr2] ...................Theta Regressionen 1,2/
                                   |1| Korrelation (kor)
                                   |2| Kovarianz (cov)
                                   |3| Determinatinskoeffizient (det)
                                   |4| Redundanz (red)
     [qQ]  ....................... Theta Q:
                                   |1| Differenz (Diff)
                                   |2| Quotient (Quot)
                                   |3| Summe (Summ)
                                   |4| Produkt (Prod)
     [v]  .......................  n zu Theta P (v)
     [m]  .......................  n zu Theta S11,S12 (m)
     [n]  .......................  n zu Theta S21,S22 (n)
     [s]  .......................  n Subpopulationen (s)
     [x]  .......................  Vergleichswert x
     [g]  .......................  |1| Wertebereich ganzzahlig

## Theta S

Usage:

     Theta_S [sd] [min] [max] [qq] [qp] [qs] [v] [m] [s] [[x]] [[g]]
     [sd]  ...................... Seed: |0| Zeitwert
     [min] ...................... R Minimalwert
     [max] ...................... R Maximalwert
     [qq]  ...................... Theta-Theta:
     [qp]  ...................... Theta P/
     [qs]  ...................... Theta S/
                                  |0| Harmonisches Mittel (HM)
                                  |1| Arithmetisches Mittel (AM)
                                  |2| Summe (SUM)
                                  |3| Standardabweichung (SD)
                                  |4| Populationsvarianzschaetzung (VAR)
                                  |5| Produktsumme(PSM)
                                  |6| Geometrisches Mittel(GM)
                                  |7| Schrausser's d (D)
                                  |8| DvarO (DV)
      [v]  .....................  n zu Theta P (v)
      [m]  .....................  n zu Theta S (m)
      [s]  .....................  n Subpopulationen (s)
      [x]  .....................  Vergleichswert x
      [g]  .....................  |1| Wertebereich ganzzahlig

## Verteilungsform

Usage: 

     Verteilungsform [min] [max] [n] [s]
      [min] ....................... Minimalwert
      [max] ....................... Maximalwert
      [n] .......... n zu Kennwert Theta=sum(x)
      [s] ................... n Subpopulationen

## Verteilungsform_2u

Usage:

      Verteilungsform_2u [min] [max] [q] [n1] [n2] [s] [xd] [g]
      [min] ............... Minimalwert
      [max] ............... Maximalwert
      [q] ................. Theta:
                            |0|................. Harmonisches Mittel
                            |1|................. Arithmetisches Mittel
                            |2|................. Summe
                            |3|................. Standardabweichung
                            |4|................. Populationsvarianzschätzung
                            |5|................. Produktsumme 
                            |6|................. Geometrisches Mittel
                            |7|................. Schrausser's d
                            |8|................. DvarO
      [n] ................. n1 zu Theta
      [n] ................. n2 zu Theta
      [s] ................. n Subpopulationen
      [xd] ................ Vergleichsdifferenzwert
      [g] ................. |1| Wertebereich ganzzahlig

## Verteilungsform_kor

Usage:

       Verteilungsform_kor [min] [max] [q] [n] [s] [x]
       [min] ............... Minimalwert
       [max] ............... Maximalwert
       [q] ................. Theta:
                             |1|................. Produktmoment Korrelation
                             |2|................. Kovarianz
                             |3|................. Determinationskoeffizient
                             |4|................. Redundanz
                             |5|................. Regressionskoeffizient ayx
                             |6|................. Regressionskoeffizient byx
                             |7|................. Regressionskoeffizient axy
                             |8|................. Regressionskoeffizient bxy
      [n] .................. n zu Theta
      [s] .................. n Subpopulationen


## References

Schrausser, D. G. (2009). *ThetaWin: Overview*. https://www.academia.edu/81800920

———. (2023a). *Schrausser/FunktionWin: Windows Interface for distribution functions* (v1.0.0). Zenodo. https://doi.org/10.5281/zenodo.7651661

———. (2023b). *Schrausser/ThetaWin: Distribution simulator* (v1.0.0). Zenodo. https://doi.org/10.5281/zenodo.7659264

———. (2024). Handbook: Distribution Functions  (Verteilungs Funktionen). PsyArXiv. https://doi.org/10.31234/osf.io/rvzxa

