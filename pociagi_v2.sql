-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Czas generowania: 14 Lut 2023, 21:16
-- Wersja serwera: 10.4.27-MariaDB
-- Wersja PHP: 8.0.25

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Baza danych: `pociagi_v1`
--

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `pociag`
--

CREATE TABLE `pociag` (
  `Id_poc` int(11) NOT NULL,
  `Nazwa_poc` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `pociag`
--

INSERT INTO `pociag` (`Id_poc`, `Nazwa_poc`) VALUES
(1, 'SIZD');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `stacje`
--

CREATE TABLE `stacje` (
  `Id_przy` int(11) NOT NULL,
  `Nazwa_stacji` varchar(20) NOT NULL,
  `Poz_x` int(11) NOT NULL,
  `Poz_y` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `stacje`
--

INSERT INTO `stacje` (`Id_przy`, `Nazwa_stacji`, `Poz_x`, `Poz_y`) VALUES
(3, 'Męcka Wola', 24, 20),
(1, 'Sieradz', 23, 20),
(2, 'Zduńska Wola', 25, 21),
(4, 'Gdańsk', 20, 3),
(5, 'Szczecin', 1, 8),
(6, 'Suwalki', 2, 210);

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `trasa`
--

CREATE TABLE `trasa` (
  `Id_poc` int(11) NOT NULL,
  `Id_przy` int(11) NOT NULL,
  `Id_trasy` int(11) NOT NULL,
  `Nr_przystanku` int(11) NOT NULL,
  `Godzina_odjazdu` time NOT NULL,
  `Godzina_przyjazdu` time NOT NULL,
  `Data` date NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `trasa`
--

INSERT INTO `trasa` (`Id_poc`, `Id_przy`, `Id_trasy`, `Nr_przystanku`, `Godzina_odjazdu`, `Godzina_przyjazdu`, `Data`) VALUES
(1, 1, 1, 1, '07:05:00', '07:00:00', '2023-02-01'),
(1, 2, 1, 2, '07:21:00', '07:20:00', '2023-02-01'),
(1, 2, 1, 3, '07:45:00', '07:44:00', '2023-02-01'),
(1, 3, 1, 4, '08:00:00', '08:01:00', '2023-02-01'),
(1, 1, 1, 5, '00:00:00', '08:01:00', '2023-02-01');

-- --------------------------------------------------------

--
-- Struktura tabeli dla tabeli `trasy`
--

CREATE TABLE `trasy` (
  `Id_poc` int(11) NOT NULL,
  `Ilosc_przy` int(11) NOT NULL,
  `Stacja_pocz` varchar(20) NOT NULL,
  `Stacja_Kon` varchar(20) NOT NULL,
  `Id_trasy` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Zrzut danych tabeli `trasy`
--

INSERT INTO `trasy` (`Id_poc`, `Ilosc_przy`, `Stacja_pocz`, `Stacja_Kon`, `Id_trasy`) VALUES
(1, 5, 'Sieradz', 'Zduńska Wola', 1);

--
-- Indeksy dla zrzutów tabel
--

--
-- Indeksy dla tabeli `pociag`
--
ALTER TABLE `pociag`
  ADD PRIMARY KEY (`Id_poc`),
  ADD KEY `Id_poc` (`Id_poc`);

--
-- Indeksy dla tabeli `stacje`
--
ALTER TABLE `stacje`
  ADD PRIMARY KEY (`Id_przy`),
  ADD KEY `Id_przy` (`Id_przy`),
  ADD KEY `Nazwa_stacji` (`Nazwa_stacji`);

--
-- Indeksy dla tabeli `trasa`
--
ALTER TABLE `trasa`
  ADD KEY `Id_poc` (`Id_poc`),
  ADD KEY `Id_przy` (`Id_przy`),
  ADD KEY `Id_trasy` (`Id_trasy`);

--
-- Indeksy dla tabeli `trasy`
--
ALTER TABLE `trasy`
  ADD PRIMARY KEY (`Id_trasy`),
  ADD KEY `Id_trasy` (`Id_trasy`),
  ADD KEY `Id_poc` (`Id_poc`),
  ADD KEY `Ilosc_przy` (`Ilosc_przy`),
  ADD KEY `Stacja_pocz` (`Stacja_pocz`),
  ADD KEY `Stacja_Kon` (`Stacja_Kon`);

--
-- AUTO_INCREMENT dla zrzuconych tabel
--

--
-- AUTO_INCREMENT dla tabeli `pociag`
--
ALTER TABLE `pociag`
  MODIFY `Id_poc` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- Ograniczenia dla zrzutów tabel
--

--
-- Ograniczenia dla tabeli `trasa`
--
ALTER TABLE `trasa`
  ADD CONSTRAINT `trasa_ibfk_1` FOREIGN KEY (`Id_przy`) REFERENCES `stacje` (`Id_przy`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasa_ibfk_2` FOREIGN KEY (`Id_poc`) REFERENCES `pociag` (`Id_poc`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasa_ibfk_3` FOREIGN KEY (`Id_trasy`) REFERENCES `trasy` (`Id_trasy`) ON DELETE CASCADE ON UPDATE CASCADE;

--
-- Ograniczenia dla tabeli `trasy`
--
ALTER TABLE `trasy`
  ADD CONSTRAINT `trasy_ibfk_1` FOREIGN KEY (`Id_poc`) REFERENCES `pociag` (`Id_poc`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasy_ibfk_2` FOREIGN KEY (`Stacja_pocz`) REFERENCES `stacje` (`Nazwa_stacji`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `trasy_ibfk_3` FOREIGN KEY (`Stacja_Kon`) REFERENCES `stacje` (`Nazwa_stacji`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
