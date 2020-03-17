/*
 * Copyright (C) 2019-2020 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "client_gui.h"

#include <multipass/cli/client_common.h>
#include <multipass/top_catch_all.h>

#include <QApplication>

namespace mp = multipass;

namespace
{
int main_impl(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("multipass-gui");

    mp::ClientConfig config{mp::client::get_server_address(), mp::RpcConnectionType::ssl,
                            mp::client::get_cert_provider()};
    mp::ClientGui client{config};

    return client.run(app.arguments());
}
} // namespace

int main(int argc, char* argv[])
{
    return mp::top_catch_all("client", main_impl, argc, argv);
}
