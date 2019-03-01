;; ;;;; se da o lista neliniara. sa se stearga cel mai mare diviz com al listei la orice nivel

;;; Calculeaza cmmdc a 2 nr prin scaderi repetate
(defun xcmmdc (nr1 nr2)
    (cond
        ((eq nr1 nr2) nr1)
        ((> nr1 nr2) 
            (xcmmdc (- nr1 nr2) nr2)
        )
        (T 
            (xcmmdc (- nr2 nr1) nr1)
        )
    )
)

;; Parcurge fiecare element din lista, calculeaza cmmdc, luand maxim-ul calculat anterior
;; In caz ca avem doar un element, il returnam
;; In caz ca nu avem elemente, returnam -1
(defun parcurgere (l)
    (cond
        ((null l) -1)
        ((and (null (cdr l)) (not (listp (car l)))) (car l))
        ((listp (car l)) 
            (xcmmdc (parcurgere (cdr l)) (parcurgere (car l)))
        )
        (T (xcmmdc 
                (xcmmdc (car l) (cadr l)) 
                (parcurgere (cddr l))
            )
        )
    )
)

(defun f (l) 
    (cond 
        ((null l) 10) 
        ((null (cdr l)) l)
        ;; ((null (cdr l)) (car l))
        ((numberp (car l)) 
            (xcmmdc (car l) (f (cdr l)))
        )
        (T 
            (xcmmdc 
                (f (car l) )
                (f (cdr l))
            )
        )
    )
)

;; (defun myremove (l e) 
;;     (cond 
;;         ((null l ) nil)
;;         ((eq l e) nil)
;;         ((not (eq l e)) l)
;;         (T (apply #'append (mapcar #'myremove l e)))
;;     )
;; )
;; ;; Call this to get the result
(defun main (l)
    ;; parcurge lista si afla cmmdc
    ;; (write (delete (parcurgere l) l))
    (write (f l))
    (write (delete (f l) l))
    ;; (write (myremove (f l) l))
    
;; asta e la final - x este cmmdc
)

(main '(10 20 10 (20 40 (50 70 (1000 100)))))