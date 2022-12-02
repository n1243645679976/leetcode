    long inv(long a) {
        if (a == 1) return 1;
        return (p - p / a) * inv(p % a) % p;
    }