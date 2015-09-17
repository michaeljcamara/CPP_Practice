#lang racket

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Michael Camara
; Honor Code Pledge: This work is mine unless otherwise cited
; Lab 3: Expressions in Other Languages
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

"Problem 1(a)"
(define r 10)
(* 4 pi (sqr r))

"Problem 1(b)"
(* (/ 4 3) pi r r r)

"Problem 1(c)"
(define a 1.2)
(define b 2.3)
(define c 3.4)
(define x -2)
(+ (* a (sqr x)) (* b x) c)

"Problem 1(d)"
(define s "Hello, Racket")
(define mid (floor (/ (string-length s) 2)))
mid

"Problem 1(e)"
(string-append (substring s 0 mid) "Dr." (substring s mid))

"Problem 1(f)"
(define (area r)
  (* 4 pi (sqr r))
)
(area 10)
(area 20)
(area 30)

"Problem 1(g)"
(define (vol r)
  (* (/ 4 3) pi r r r)
)
(vol 10)
(vol 20)
(vol 30)

"Problem 1(h)"
(define (midpt s)
  (floor (/ (string-length s) 2))
)
(midpt "a string")
(midpt "dr. racket")
(midpt "abcde")

"Problem 1(i)"
(define (insert s t)
  (string-append (substring s 0 (midpt s)) t (substring s (midpt s)))
)
(insert "Interrupting cow" "moo")
(insert "My name is Camara     " "Michael Joseph ")
(insert "This is another example" "ta-dah!")