# ThetaWin
Console applicationes for distribution functions implemented in FunktionWin (see Schrausser, 2011, 2023a, res.).
Theta applications 
generating distributions and estimators for several parameters q within different designs via bootstrap method. Implemented in ThetaWin (see Schrausser, 2009, 2023b, res.).

## Binomial

Usage: 

     Binomial [p] [k] [n] [[1]]
     [p] .............. probability of event A
     [k] .............. n of events A
     [n] ...............n of trials
     [1] ............. (1) full output

## Binomial_T

Usage: 

     Binomial_T [b] [c] [[1]]
     [b] ............. cell count b
     [c] ............. cell count c
     [1] ............ (1) full output

## epsilon

Usage: 

     epsilon [mode] [Q0] [s] [n] [e|Q1] [p] [df] [[x]]
     [mode] ...................... (1)Effect-size (2)Theta.1
     [Q0] ..............................Theta.0
     [s] ................................ Standard deviation
     [n] ................................ n of cases
     [e|Q1] .......................... Epsilon | Theta.1
     [p] ................................ Percent-level (0.00)
     [df] .............................. Degrees of freedom n - (.)
     [x] ................................ Test value

## F_Function

Usage:
 
      F_Function [mode] [x] [n1] [n2]
      [mode] ...................... (1)Fx=p->F (2)Fy=F->p
      [x] ................................ p-Wert/F-Wert
      [n1] ............................. n1
      [n2] ............................. n2

## Fisher_Exact

Usage: 

      Fisher_Exact [a] [b] [c] [d] [[1]]
      [a][b][c][d] ................. cell counts a,b,c,d
      [1] ..............................(1) full output

## Fisher_Z

Usage: 

      Fisher_Z [mode] [x]
      [mode] ......... (1)r->Z (2)Z->r
      [x] .................. r-value/Z-value

## GAMMA_Function

Usage: 

      GAMMA_Function [mode] [value]
      [mode] .................. (1)F(x)->⌈ (2)F'(⌈)->x
      [value] .................... x / ⌈

## GAMMA

Usage: 
 
      GAMMA [n] [input] [output]
      [n] .................... n of cases
      [input] .............. input file
      [output] ........... output file

## Geometric

Usage: 

      Geometric [p] [r+1] [[1]]
      [p] .................. probability of event A
      [r+1] .............. n of trials
      [1] .................. (1) full output

## Hypergeometric

Usage: 

      Hypergeometric [k] [n] [N] [K] [[1]]
      [k] ................... n of events A in Sub-Population
      [n] ................... size of Sub-Population
      [N] ................... size of Population
      [K] ................... n of events A in Population
      [1] ................... (1) full output


## Poisson

Usage:

      Poisson [p] [k] [n] [[1]]
      [p] .................. probability of event A
      [k] .................. n of events A
      [n] .................. n of trials
      [1] ................. (1) full output

## t_Function

Usage:

      t_Function [mode] [x] [n]
      [mode] ........ (1)Fx=p->t (2)Fy=t->p
      [x] ................ p-value/t-value
      [n] ................ n of cases

## x2_Function

Usage: 

      x2_Function [mode] [x] [n]
      [mode] ....... (1)Fx=p->x² (2)Fy=x²->p
      [x] ................ p-value/x²-value
      [n] ................ n of cases

## z_Dichte

Usage: 

      z_Dichte [modus] [wert] [[f]]
      [modus] ............. (1)fx=z->d (2)fy=d->z (3) ∫x=z->p
                                   (4) ∫'p->z  (5) ∫'p->d  (6) ∫y=d->p
      [wert] .................. z-Wert/z-Dichte/Prozentrang p
      [f] ....................... (1)z-Dichte Funktionsgraph

## z_Function

Usage: 

      z_Function [mode] [x]
      [mode] ............. (1)Fx=p->z (2)Fy=z->p
      [x] ..................... p-value/z-value


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
      [n] ................. n zu Theta
      [s] ................. n Subpopulationen


## References

chrausser, D. G. (2011). *Handbook Distribution Functions (Verteilungsfunktionen)*. https://www.academia.edu/96844355

Schrausser, D. G. (2023). *Schrausser/FunktionWin: Windows Interface for distribution functions (v1.0.0)*. Zenodo. https://doi.org/10.5281/zenodo.7651661

Schrausser, D. G. (2023). *Schrausser/ThetaWin: Distribution simulator (v1.0.0)*. Zenodo. https://doi.org/10.5281/zenodo.7659264
