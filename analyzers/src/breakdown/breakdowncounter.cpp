//------------------------------------------------------------------------------
// Author: Andrey Kuznetsov
// Description: Statistics counter
// Copyright (c) 2015 EPAM Systems
//------------------------------------------------------------------------------
/*
    This file is part of Nfstrace.

    Nfstrace is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, version 2 of the License.

    Nfstrace is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Nfstrace.  If not, see <http://www.gnu.org/licenses/>.
*/
//------------------------------------------------------------------------------
#include <algorithm>
#include <numeric>

#include "breakdowncounter.h"
//------------------------------------------------------------------------------
using namespace NST::breakdown;
//------------------------------------------------------------------------------
BreakdownCounter::BreakdownCounter(size_t count)
    : latencies(count, NST::breakdown::Latencies())
{
}

BreakdownCounter::~BreakdownCounter()
{
}

Latencies& BreakdownCounter::operator[](int index)
{
    return latencies[index];
}

uint64_t BreakdownCounter::get_total_count() const
{
    return std::accumulate(std::begin(latencies), std::end(latencies), 0, [](int sum, const NST::breakdown::Latencies& latency) {
        return sum + latency.get_count();
    });
}

const Latencies BreakdownCounter::operator[](int index) const
{
    return latencies[index];
}
//------------------------------------------------------------------------------
