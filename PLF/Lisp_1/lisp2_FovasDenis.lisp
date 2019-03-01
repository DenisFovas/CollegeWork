;;;; Convert a tree of type 1 into a tree of type 2
;;; Algoritm:
;;; 1. Split the list into a series of numbers and nodes
;;; 2. go trough the list of numbers. If it has 
;;; children, make a list and go deeper w\ the childs 
;;; and apply the same algorithm. Otherwise, end.
(defun getNumbers (tree) 
    (cond 
        ((null tree) nil)
        ((numberp (car tree)) (cons (car tree)
            (getNumbers (cdr tree)))
        )
        (T (getNumbers (cdr tree)))
    )
)
(defun getNodes (tree)
    (cond 
        ((null tree) nil)
        ((not (numberp (car tree))) (cons (car tree) (getNodes (cdr tree))))
        (T (getNodes (cdr tree)))
    )
)

(defun SplitTree (numbers nodes) 
    ;; (setq root (car nodes)
    (cond
        ;; End the call
        ((null numbers) nil)
        ;; One node only left
        ((null (cdr nodes) ) (list nodes))
        ;; If we have 0 children
        ((eq (car numbers) 0) (car nodes))
        ;; If we have 1 children
        ((eq (car numbers) 1) 
            (cons (car nodes) 
                (list (SplitTree (cdr numbers) (cdr nodes)))
            )
        )
        ;; If we have 2 children
        ((eq (car numbers) 2) 
            (cons 
                (car nodes)
                (cons
                    (list (SplitTree (cdr numbers) (cdr nodes)))
                    (list 
                        (SplitTree (cddr numbers) (cddr nodes))
                    )
                )
            )
        )
    )
)


(defun changeType (tree)
    ;; Get the numbers
    (setq numbers (getNumbers tree))
    ;; get the nodes
    (setq nodes (getNodes tree))
    (SplitTree numbers nodes)
)

;;; Run main
(write (changeType '(A 2 B 0 C 2 D 0 E 0)))
(write (changeType '(A 0 )))
;; (write (changeType '(A 2 B 2 C 0 D 0 E 0)))
;; (write (changeType '(A 2 b 2 c 1 e 0 d 0 f 0)))