; Name: Ahmed Kiel-Kamil

; -------------------------------------------------------------
; CIRCLE
; -------------------------------------------------------------

(define (circle-area r)
  (* pi r r))

(define (circle-circumference r)
  (* 2 pi r))

; -------------------------------------------------------------
; RECTANGLE
; -------------------------------------------------------------

(define (rectangle-area length width)
  (* length width))

(define (rectangle-perimeter length width)
  (* 2 (+ length width)))

; -------------------------------------------------------------
; RIGHT TRIANGLE
; -------------------------------------------------------------
; base = b, height = h
; hypotenuse = sqrt(b^2 + h^2)

(define (right-triangle-hypotenuse b h)
  (sqrt (+ (* b b) (* h h))))

(define (right-triangle-area b h)
  (/ (* b h) 2))

(define (right-triangle-perimeter b h)
  (+ b h (right-triangle-hypotenuse b h)))

; -------------------------------------------------------------
; REGULAR PENTAGON (side length = s)
; -------------------------------------------------------------
; Area formula: A = (1/4)*sqrt(5(5+2sqrt(5))) * s^2
; Perimeter = 5s

(define (pentagon-area s)
  (* (/ 1 4)
     (sqrt (* 5 (+ 5 (* 2 (sqrt 5)))))
     (* s s)))

(define (pentagon-perimeter s)
  (* 5 s))

; -------------------------------------------------------------
; OUTPUT SECTION
; -------------------------------------------------------------

(display "===== CIRCLE (radius 5) =====") (newline)
(display "Area: ") (display (circle-area 5)) (newline)
(display "Circumference: ") (display (circle-circumference 5)) (newline) (newline)

(display "===== RECTANGLE (length 10, width 4) =====") (newline)
(display "Area: ") (display (rectangle-area 10 4)) (newline)
(display "Perimeter: ") (display (rectangle-perimeter 10 4)) (newline) (newline)

(display "===== RIGHT TRIANGLE (base 3, height 4) =====") (newline)
(display "Area: ") (display (right-triangle-area 3 4)) (newline)
(display "Perimeter: ") (display (right-triangle-perimeter 3 4)) (newline) (newline)

(display "===== REGULAR PENTAGON (side length 6) =====") (newline)
(display "Area: ") (display (pentagon-area 6)) (newline)
(display "Perimeter: ") (display (pentagon-perimeter 6)) (newline)

; Algorithm (in plain English):
; 1. Define a function for the area and circumference of a circle using radius.
; 2. Define a function for the area and perimeter of a rectangle using length and width.
; 3. Define a function for the area and perimeter of a right triangle using base and height.
;    - Hypotenuse is found using the Pythagorean theorem.
; 4. Define a function for the area and perimeter of a regular pentagon with side length.
;    - Use the known formula for a regular pentagon.
; 5. For each shape, call its functions with sample values.
; 6. Print labeled results for each shape so the output is clear.
; 7. Program ends after printing all values.