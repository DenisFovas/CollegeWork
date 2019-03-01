; Atomii de pe nivelul K sunt inlocuiti cu 0
;; (defun append1 (l1 l2) 
;;     (cond 
;;         (null l1) l2)
;;         (T (cons 
;;             (car l1) 
;;             (append1 (cdr l1) l2))))

;; (defun f(lista K)
;;     (cond 
;;         ((and (atom lista) (eq k 0)) 0)
;;         ((and (atom lista) (not (eq k 0))) lista)
;;         ((listp lista) 
;;             (apply #'append1 (mapcar #'(lambda (X) (f X K)) lista))
;;         )
;;     )
;; )

;; (write (f '(1 2 (a 3 (b 3) (3 g)) 32 c (23 a)) 3))
(defun sum(l) 
    (cond 
        ((null l) 0)
        ((numberp l) l)
        (T (apply '+ (mapcar #'sum l)))))

(defun f1(l level) 
    (cond 
        ((null l) nil)
        ((eq (mod level 2) 0) 
            (append (mapcar #'(lambda (X) (f1 X(+ level 1))) l)
        )
        (T
            (and 
                (if (eq (mod (sum l) 2 ) 0) l nil)
                (cons (mapcar #'(lambda (X) (f1 X(+ level 1))) l))
            )
         )
    )
)

(defun mainf1 (l) 
    (write (f1 (list l) 1)))

(f1 '(1 2 (a 3 (b 3) (3 g)) 32 c (23 a)) 3)