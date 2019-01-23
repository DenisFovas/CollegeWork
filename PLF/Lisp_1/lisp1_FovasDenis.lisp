;;;; Necesar pentru a putea rezolva problemele
(defun append1 (l1 l2)
    (cond 
        ((null l1) l2)
        (T (cons (car l1) (append1 (cdr l1) l2)))
    )
)





;;;; Return the n-th element from a list

(defun NElement (Lista N)
    (cond
        ((NULL Lista) Nil)
        ((EQ N 1) (car Lista))
        (T 
            (NElement 
                    (CDR Lista)
                    (- N 1)
            )
        );Close the T
    )
)

;;; Check if an atom is a member of a 
;;; list (non linear)
(defun CheckAtom (Lista Atom)
    (cond 
        ((null Lista) Nil)
        ((EQ (CAR Lista) Atom) T)
        (T (CheckAtom (CDR Lista) Atom))
    )
)



;;; Determine the list of subsets 
;;; @ any level
(defun DetermineSubsets (Lista)
    (cond 
        ;; Exit
        ((NULL Lista) (values))
        ;; If we don't have a list as the first element, we 
        ;; will go deeper into the list and continue the algorithm
        ((atom (car lista)) (DetermineSubsets(cdr lista)))
        ;; If we have a list in the front, we will return it 
        ;; with the result of the function applied to the first 
        ;; element, the list, and to the rest of the list 
        ;; (to can continue the recursion)
        ((listp (car lista))
            (cons (car lista) (append1 (DetermineSubsets(car lista)) (DetermineSubsets(cdr lista))))
        )
    )
)

;;; The main function which will return the result
(defun mainDetermineSubsets (lista) 
    (cons lista (DetermineSubsets lista))
)
;;; Transform a linear list into a set
(defun ListToSet (l)
    (cond 
        ((Null l) nil)
        ((member (car l) (cdr l)) (ListToSet(cdr l)))
        (T (cons (car l) (ListToSet (cdr l))))
    )
)

;;; Run all
(format t "N-th element: ") 
(write (NElement '(1 2 3 0 5 6 7 8) 4) )
(format t "~%")
(format T "Check if element is in list: ")
(write (CheckAtom '(1 2 3 4 5) 4))
(format t "~%")
(format t "List of Subsets: ")
(write (mainDetermineSubsets '(
            1 2 3 (4 5) (6 7 (8 9))
        )
    ) ;; For the function call
)
(format t "~%")
(format t "Linear list to set: ")
(write (ListToSet '(1 2 3 4 2 1 6)))