;;;; Write a function that returns the sum of numeric atoms in 
;;;; a list, at any level.
;; (defun suma(l)
;;     (cond 
;;         ((numberp l) l)
;;         ((atom l) 0)
;;         (T (apply #'+ (mapcar #' suma l)))
;;     )
;; )

;; (write (suma '(1 2 3 a v s (4 5 (6) b) 7 b (8 nadsa 9 (10)))))

(defun ptNicole (lista element) 
    (cond 
        ((eq lista element) nil)
        ((not (eq lista element)) lista)
    )
)