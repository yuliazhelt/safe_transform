# safe_transform

The TransformIf function, which takes 2 iterators specifying a sequence,
a unary predicate p and a functor f, and applies this functor to all elements of the sequence for which the specified
predicate is executed. It is assumed that f modifies the passed element (accepts by reference), so this function, unlike std::transform, works in-place.
