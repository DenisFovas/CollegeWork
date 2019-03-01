
(defun leftsubtree (l)
	(leftsubtree2 (cddr l) 1)
)

(defun leftsubtree2 (l c)
	(cond
		((null l) nil)
		((equal c 0)  nil)
		(T 
			(append 
				(subseq l 0 2) 
				(leftsubtree2 
					(cddr l) 
					(- (+ (cadr l) c) 1)
				)
			)
		)
	)
)

(defun rightsubtree (l)
	(subseq l (+ (length (leftsubtree2 (cddr l) 1)) 2) (length l))
)

(defun inorder (l)
	(cond
		((null l) nil)
		(T (append 
				(inorder 
					(leftsubtree l)
				) 
				(list (car l)) 
				(inorder (rightsubtree l)) 
			)
		)
	)
)