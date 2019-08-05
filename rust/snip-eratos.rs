fn Is_prime(num: i32)->bool{
    if num <= 0{
        return false;
    }else{
        let mut r = 2;
        while r * r <= num{
            if num % r == 0{
                return false;
            }
            r += 1;
        }
    }
    return true;
}
