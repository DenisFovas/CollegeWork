% Write a predicate to determine all decomposition of n
% (n given, positive), as sum of consecutive natural numbers.

% Make a list of 1, so that we have n elements of 1 in the 
% array.
% Flow Model: (i, o)
makeOnes(0, []) :- !.
makeOnes(N, [1 | Rone]) :-
	N1  is N - 1,
	makeOnes(N1, Rone).

% Changes the list to a combination of sums of the elements
% If the list is empty, Then we have the answer figured out
% (i, i, o)
changeList([], TempList, TempList).

% Generate as Head is the sum, then figure out other 
% posibilities
changeList([H1, H2 | T], TempList, R) :-
	H3 is H1 + H2,
	changeList([H3 | T], TempList, R).

% Consider the head in the  list rezulted.
changeList([H | T], TempList, R) :-
	changeList(T, [H | TempList], R).

% Check if the list is consective
% An empty list has the elements consecutive
check([]).
% A list with one element has the elemnets conssecutive
check([X]).
% we check the first 2 elements, then we go deeper into the list
check([H1, H2 | T]) :-
	H1 =< H2,
	check([H2 | T]).
% Makes the list of elements of one, then will compute the posibilites
% (i, o)
main(N, R) :-
	makeOnes(N, ListOfOnes),
	changeList(ListOfOnes, [], R),
	check(R).