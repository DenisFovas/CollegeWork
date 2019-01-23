% 8
% a. Write a predicate to determine if a list has even 
% numbers of elements without counting the elements from 
% the list.
% b. 
% Write a predicate to delete first occurrence of the 
% minimum number from a list.
 
% Exercise 8. a.
% The function will just return true/false if the list is with
% an odd length or even length
% flow: even(i)
 
% If we have an empty list, we have a fact, that it's even.
even([]).
% If we have a lsit with at least a head, we can go to the 
% odd function, to can check if there is another element, to 
% can continue with the recursion.
even([H | T]) :-
    odd(T).

% Go to the even function, check if there is another element.
% flow: odd(i)
odd([H | T]) :-
    even(T).

% Exercise 8. b.

% flow: minim(i, i, o)
% Compute the minimum value beetwhen 2 numbers
minim(Number1, Number2, Min) :-
    Number1 > Number2,
    Min is Number2.
minim(Number1, Number2, Min) :-
    Number1 =< Number2,
    Min is Number1.

% flow: minimFromList(i, o)
% A list with one element will have only one element 
% to be compared with
minimFromList([X], X).

% Get the minimum value from the list. 
% Will go trough it, then when the list is with only one element
% it will start comparing the minimum values of the list.
% Then, when it stops it assigns the minium value to the 
% MinValue variable.
minimFromList([H | T], MinValue) :-
    minimFromList(T, NewMin),
    minim(H, NewMin, Minimum),
    MinValue is Minimum.

% flow: removeFromList(i, i, o)
% We can't remove from an empty list.
removeFromList([], _, []).

% When we have the situation that the second value is
% the same as for the head of the list, we will return false, 
% we stop the execution to repeat. 
% God bless _Stack Overflow_
removeFromList([H | T], H, T) :- !.


% We will go into the list as deep as we can, until we will
% find the value that is equal to the head (rule from above).
% then we will return false to not go deeper with the 
% check, to can remove only the first value.
removeFromList([H | T], X, [H | NewTail]) :- 
    removeFromList(T, X, NewTail).


% flow: removeMain(i)
% Main program to delete the list. It will compute the 
% minimum value of the list, then it will remove the first 
% element from the list, then it will display the list.
removeMain(List) :-
    minimFromList(List, Value),
    removeFromList(List, Value, NewList),
    write(NewList).