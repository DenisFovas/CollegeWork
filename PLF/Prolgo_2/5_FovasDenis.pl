% a. 
% Substitute all occurrences of an element of a 
% list with all the elements of another list. 
% Eg. subst([1,2,1,3,1,4],1,[10,11],X) produces 
%       X=[10,11,2,10,11,3,10,11,4].

% Flow model: 
%       append(i, i, o)
% If we append at an empty list, we will get the 
% list we got as the second parameter.
append([], X, X).
% We go deeper into the list. When we reach the empty list, 
% we will have only one element. Then we recompose the 
% list as tail and the head. 
append([H | T], Element,  [H | X]) :-
    append(T, Element, X).
%    X is [H | Y].

% Flow model: 
%       subst(i, i, i, o)
% If we have an empty list, we return an empty list.
subst([], _, _, []).
% We have the first element as the number we need to replace.
subst([Nr | T], Nr, SecondList, X) :-
    subst(T, Nr, SecondList, Xb),
    append(SecondList, Xb, X).
% If we don't have the first element as the element, we will 
% need to go deeper into the list.
subst([H | T], Nr, SecondList, [H | X]) :-
    H =\= Nr,
    subst(T, Nr, SecondList, X).

% b. 
% For  a  heterogeneous  list,  formed  from  integer  
% numbers and  list  of  numbers,  replace  in  every  
% sublist  all occurrences of the first element from 
% sublist it a new given list.
% Eg.: [1, [4, 1, 4], 3, 6, [7, 10, 1, 3, 9], 5, 
%           [1, 1,1], 7] si [11, 11] =>
% [1, [11, 11, 1, 11, 11], 3, 6, [11, 11, 10, 1, 3, 9], 
% 5, [11 11 11 11 11 11], 7]

% Will go into the list and will substitute the Head 
% element from the list, using the function from point a.
replaceInLIst([H|T], SecondList, X) :-
    subst([H | T], H, SecondList, X).

% Flow model:   (i, i, 0)
% For an empty list, we will replace nothing.
replaceFirst([], _, []).

% If the head is not a sublist, we will go deeper into 
% the main list and try to find another list
replaceFirst([H | T], SecondList, [H | X]) :-
    not(is_list(H)),
    replaceFirst(T, SecondList, X).

% If the head of the list is a sublist, we will go into 
% the function replaceInList, where it will use the subst 
% function to replace the elements.
replaceFirst([H | T], SecondList, [Y | X]) :-
    is_list(H),
    replaceInLIst(H, SecondList, Y),
    replaceFirst(T, SecondList, X).