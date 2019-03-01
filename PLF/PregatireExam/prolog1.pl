% % Program care sterge al 2-lea, 6lea, 10-lea element din lista
% % program(Lista, Lista)
% % program(i, o)
% program([], _, []).
% program([H | T], N, R) :-
%     N1 is N + 2,
%     N1 mod 4 =:= 0,
%     N2 is N + 1,
%     program(T, N2, R).
% program([H | T], N, [H | R]) :-
%     N1 is N + 2,
%     N1 mod 4 =\= 0,
%     N2 is N + 1,
%     program(T, N2, R).

% mainCall(L, R) :-
%     program(L, 1, R).

% calculPrimN(0, 0).
% calculPrimN(1, 1).
% calculPrimN(N, R) :-
%     N1 is N - 1,
%     calculPrimN(N1, R1),
%     R is R1 + N.

% calculN(N, R) :-   
%     N1 is N + 1,
%     Prod is N * N1,
%     R is Prod div 2.
    

% Time for Backtracking... Yey

% se da o lista - genereaza 
% lista submultimilro cu K elemente in prog aritmetica
checkProgresieAritmetica([], _).
checkProgresieAritmetica([_], _).
checkProgresieAritmetica([H1, H2], R) :-   
    R is H2 - H1.

checkProgresieAritmetica([H1, H2 | T], R) :-
    checkProgresieAritmetica(T, R1),
    R is H2 - H1,
    R =:= R1,

% addToList([], _, []).
addToList([], 0, []).
addToList([H | _], 0, H).
addToList([H | T], K, [H | R1]) :-
    K1 is K - 1,
    addToList(T, K1, R1).
addToList([_ | T], K, R) :-
    addToList(T, K, R).

main1(L, K, R) :-
    addToList(L, K, R),
    checkProgresieAritmetica(R, K).

% main(L, N, R) :-
    % findall(X, generate(L, X), R), 
    % write(R).