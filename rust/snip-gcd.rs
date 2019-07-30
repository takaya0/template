fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let r = a % b;
        a = b; b = r;
    }
    a
}

