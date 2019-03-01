;Find the path from the root to a given node (n-ary trees)

(defun myOr(L)
	(cond
		( (null L) nil)
		( (car  L) t  )
		(t (myOr (cdr L)) )
	)
)

(defun exists(L E)	;checkes whether the atom E is in the list L (at any level)
	(cond
		( (and (atom L) (equal L E)) T)
		( (atom L) NIL)
		( T (myOr (mapcar #'(lambda(L)(exists L E)) L )))
	)
)

(defun path(L N)
	(cond
		( (atom L) nil)
		((exists L N) (append (list (car L))  (mapcan #'(lambda(L)(path L N)) L ) ) )	;-using mapcan in order to flatten the list
		(t nil)																			;and lose the NILs
	)
)

;Find the level of a given node. The root has level 0 (n-ary trees)
(defun level(L N)
	(cond
		((atom L)	0)
		((exists L N) (+ 1 (apply #'+ (mapcar #'(lambda(L) (level L N)) L ))))
		(T	 (apply #'+ (mapcar #'(lambda(L) (level L N)) L )) )
	)
)

(defun levelWrap(L N)
	(- (level L N) 1)
)

;Find the depth of a given n-ary tree.
(defun depth(L)
	(cond
		((atom L)	0)
		(T	(+ 1 (apply #'max (mapcar #'depth L))))
	)
)

;Find the number of nodes on a given level K of an n-ary tree
(defun nodes(L LVL K)
	(cond
		( (null L)	nil)
		( (and (equal LVL K)(atom L))	1)
		( (listp L)	(apply #'+ (mapcar #'(lambda(X)
											(nodes X (+ 1 LVL) K)			
														) L )))
		( t	0)
	)
)

(defun nodesWrap(L K)
	(nodes L -1 K)
)

;Find the nodes on a given level K of an n-ary trees

(defun nodesOnLvl(L LVL K)
	(cond
		( (null L)	nil)
		( (and (equal LVL K)(atom L))	(list L))
		( (listp L)	(mapcan #'(lambda(X)
											(nodesOnLvl X (+ 1 LVL) K)			
														) L ))
		( t	nil)
	)
)

(defun nodesOnLvlWrap(L K)
	(nodesOnLvl L -1 K)
)

;n-ary tree for testing:  '( A (B (E(H)) (F)) (C(G)) (D(I)(J)(K(L))) ) 