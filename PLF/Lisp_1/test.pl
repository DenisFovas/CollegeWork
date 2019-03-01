% lista omogena - det. produsul elementelor de pe poz pare
pozitiePara(_, 0).
pozitiePara([H], 1) :- false.
pozitiePara([H | T], N) :-
    N1 is N - 1,
    pozitiePara([T, N1]).


getpar([], _, []).
getpar([H | T], N, [H | R]) :-
    N1 is N mod 2,
    N1 =:= 0,
    N2 is N + 1,
    getpar(T, N2, R).

getpar([H | T], N, R) :-
    N1 is N mod 2,
    N1 =\= 0,
    N2 is N + 1,
    getpar(T, N2, R).


produs([], 1).
produs([H], H).
produs([H | T], R) :-
    produs(T, R1),
    R is R1 * H.

main(L) :-
    getpar(L, 1, R),
    produs(R, Rez),
    write(Rez).