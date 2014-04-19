(define presice 0.0001)

(define (aver x y)
  (/ (+ x y) 2))

(define (quot x y)
  (/ x y))

(define (abs x)
  (if (> x 0)
      x
      (- 0 x)))

(define (sqrt x)
  (* x x))

(define (distant x y)
  (abs (- x y)))

(define (bingo x y)
  (if (< (distant x (sqrt y)) presice)
      true
      false))

(define (refine x guess)
  (/ (+ (/ x
	   (sqrt guess))
	(* 2 guess))
     3))

(define (sqrtr-iter-r x guess)
  (define nguess (refine x guess))
  (if (= x (sqrt guess))
      guess
      ((if (bingo guess nguess)
	   nguess
	   (sqrtr-iter-r x (refine x nguess))))))

(define (sqrtr-r x)
  (sqrtr-iter-r x 1.0))

(sqrtr 2)

(sqrt (sqrtr 2))

(square (sqrtr 2))


