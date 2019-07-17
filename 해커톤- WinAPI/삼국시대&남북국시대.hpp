
void �ﱹ�ô�(EventManager& evt_mng) {

	{
		EventMaker e("��������", EventPriority::High);
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			data.dict["�÷��̾�"] = "�Ŷ�";
			return data.dict["�÷��̾�"] == "";
		};
	}

	{
		EventMaker e("�ﱹ����", EventPriority::High);
		e->content =
			"����� ����� ����� �������� �� ����� ���ö����ϴ�. ���� ���̵ȴٸ� �ﱹ�� �����Ͽ� �������� �ѹݵ��� ����ϰ� ����ڴٰ�...\n\
����� ���� �� ���� �츮�� ����� �������մϴ�!";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;

			if (data.dict["�ﱹ����"] != "")
				return false;

			return  evt_mng.RandomAverageTurn("�ﱹ����", 5);

		};

		{
			EventSelectItemMaker s(e, "�糪�� ������ ��û�϶�!");
			s->content =
				"�糪�� �ﱹ������ ���ʹ޶�� �м��� �����ϴ�.\n\
�η�-\n\
��-\n\
�ܱ�+";
			s->Effect = [&](Gamedata& data) {
				data.dict["�ﱹ����"] = "�м�����";
				data.player.res.human -= 1;
				data.player.res.money -= 2;
				data.player.res.diplo += 2;
			};
		}

		{
			EventSelectItemMaker s(e, "�ϴ� �� ������ �츮�� ������ �̰ܺ���!");
			s->content =
				"�� ������ �츮�� ������ �̱� �غ� �մϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�ﱹ����"] = "�������";
				data.player.res.food -= 2;
				data.player.res.human -= 2;
				data.player.res.money -= 2;
				data.player.res.milli += 5;
			};
		}

		{
			EventSelectItemMaker s(e, "������ �̸���...");
			s->content =
				"�ƹ��͵� ���� �ʴ´�.";
			s->Effect = [&](Gamedata& data) {
			};
		}
	}

	{
		EventMaker e("�м�����", EventPriority::High);
		e->content =
			"����� �м��� ���� ����� �����մϴ�.\n\
��� �Ǵ� ������ �����ұ��?";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "�м�����")
				return true;
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���ϵ�� ȸ�Ǹ� ���� ������!");
			s->content =
				"ȸ�Ǹ� �������� ���ϵ鿡�� �м��� �����ٴ� ����� �����ϰ� �����մϴ�.\n\
�����--";
			s->Effect = [&](Gamedata& data) {
				data.player.res.milli -= 10000;
			};
		}

		{
			EventSelectItemMaker s(e, "�̹���(1��� ����)���� ��Ź�Ͽ� �������� ��� �Ѹ��� ������!");
			s->content =
				"������ ��û�ϱ� ���� �̹������Ը� �м��� �����ٴ� ����� �����ϰ�\n\
�̹����� �ɺ��� �������� �ѻ���� ��õ�ش޶�� �Ѵ�.\n\
�η�-\n\
��-\n\
�ܱ�+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 1;
				data.player.res.money -= 2;
				data.player.res.diplo += 2;
				data.dict["�ﱹ����"] = "�м����޿Ϸ�";
			};
		}

		{
			EventSelectItemMaker s(e, "�׳� ���� ���� ���� ������� �ñ���!");
			s->content =
				"�������� �ɺ����� �м��� �����ٴ� ����� �����ϰ� ���� �ñ�ϴ�.\n\
��-\n\
�ܱ�+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.money -= 3;
				data.player.res.diplo += 2;
				data.dict["�ﱹ����"] = "�м����޿Ϸ�";
			};
		}
	}

	{
		EventMaker e("�м� ���� �Ϸ�", EventPriority::Normal);
		e->content =
			"�糪�� �м� ������ �Ϸ��߽��ϴ�.\n\
���������� �����ұ��?";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "�м����޿Ϸ�")
				return true;
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "����");
			s->content = "�糪��� �� �Ʒ� ���� ������ �մϴ�.\n\
��-\n\
�η�-\n\
�����-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 3;
				data.player.res.money -= 2;
				data.player.res.milli -= 1;
				data.dict["�ﱹ����"] = "�������ݿϷ�";
			};
		}

		{
			EventSelectItemMaker s(e, "����");
			s->content = "�糪�� ���밡 �ٴٷ� �Ѿ�� �� �� ���� ������ �մϴ�.\n\
��-\n\
�η�-\n\
�����-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 2;
				data.player.res.money -= 3;
				data.player.res.milli -= 1;
				data.dict["�ﱹ����"] = "�������ݿϷ�";
			};
		}
	}

	{
		EventMaker e("���� ����", EventPriority::Normal);
		e->content =
			"������ ������ ��� ���� �����ұ��?";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "�������")
				return true;
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���� ����");
			s->content =
				"������ �����մϴ�\n\
�ķ�- ~ --\n\
�α�- ~ --\n\
��-\n\
�����-";
			s->Effect = [&](Gamedata& data) {
				if (evt_mng.RandomPercent(70))
					data.player.res.food -= 2;
				else
					data.player.res.food -= 5;
				if (evt_mng.RandomPercent(70))
					data.player.res.human -= 2;
				else
					data.player.res.human -= 5;
				data.player.res.money -= 2;
				data.player.res.milli -= 1;
				data.dict["�ﱹ����"] = "�������ݿϷ�";
			};
		}

		{
			EventSelectItemMaker s(e, "���� ����");
			s->content =
				"������ �����մϴ�\n\
�ķ�- ~ -\n\
�α�- ~ -\n\
��-\n\
�����-";
			s->Effect = [&](Gamedata& data) {
				if (evt_mng.RandomPercent(80))
					data.player.res.food -= 3;
				else
					data.player.res.food -= 4;
				if (evt_mng.RandomPercent(80))
					data.player.res.human -= 3;
				else
					data.player.res.human -= 4;
				data.player.res.money -= 2;
				data.player.res.milli -= 1;
				data.dict["�ﱹ����"] = "�������ݿϷ�";
			};
		}
	}

	{
		EventMaker e("���� ����", EventPriority::Normal);
		e->content =
			"���� �ﱹ ������ ���� �������� ���ҽ��ϴ�!\n\
������ �糪�� �ణ �ɸ��׿�";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "�������ݿϷ�")
				return true;
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���� ����");
			s->content = "���� ������ ���� �ʰ� ������ �����մϴ�\n\
�ķ�-\n\
�η�+\n\
��-\n\
�����-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food -= 2;
				data.player.res.human += 1;
				data.player.res.money -= 1;
				data.player.res.milli -= 3;
				if (evt_mng.RandomPercent(50))
					data.dict["�ﱹ����"] = "�ﱹ�Ϻ�����";
				else
					data.dict["�ﱹ����"] = "���������";
			};
		}

		{
			EventSelectItemMaker s(e, "���� ���� ����");
			s->content = "��� �����Ͽ� ������ �����մϴ�\n\
�ķ�-\n\
�η�-\n\
��-\n\
�ܱ�-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food -= 2;
				data.player.res.human += 1;
				data.player.res.money -= 1;
				data.player.res.diplo -= 3;
				data.dict["�ﱹ����"] = "���������";
			};
		}
	}

	{
		EventMaker e("���� ����", EventPriority::Normal);
		e->content =
			"���� �ﱹ ������ ���� �������� ���ҽ��ϴ�!\n\
������ �糪�� �ణ �ɸ��׿�";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "�������ݿϷ�") 
				return true;
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "���� ����");
			s->content = "���� ������ ���� �ʰ� ������ �����մϴ�\n\
�ķ�-\n\
�η�+\n\
��-\n\
�����-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food -= 2;
				data.player.res.human += 1;
				data.player.res.money -= 1;
				data.player.res.milli -= 3;
				if (evt_mng.RandomPercent(50))
					data.dict["�ﱹ����"] = "�ﱹ�Ϻ�����";
				else
					data.dict["�ﱹ����"] = "���������";
			};
		}

		{
			EventSelectItemMaker s(e, "���� ���� ����");
			s->content = "��� �����Ͽ� ������ �����մϴ�\n\
�ķ�-\n\
�η�-\n\
��-\n\
�ܱ�-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food -= 2;
				data.player.res.human += 1;
				data.player.res.money -= 1;
				data.player.res.diplo -= 3;
				data.dict["�ﱹ����"] = "���������";
			};
		}
	}

	{
		EventMaker e("����� ����", EventPriority::Normal);
		e->content =
			"�ﱹ ������ ���� ������ �޾� ������ ������ ���� �츮�� �븳�ϴ�.\n\
������ �� �ҽ��� ��� ����� ����, ������ �鼺���� �츮�� �����شٰ� �ϳ׿�.\n\
������ �¼� �ο����ô�!\n\
�ķ�++\n\
�η�++\n\
��++\n\
�ܱ�--\n\
�����+";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "���������") {
				data.player.res.food += 5;
				data.player.res.human += 5;
				data.player.res.money += 5;
				data.player.res.diplo -= 5;
				data.player.res.milli += 2;
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "����� ����!");
			s->content = "��� ������ �����սô�!";
			s->Effect = [&](Gamedata& data) {
				if (evt_mng.RandomPercent(60))
					data.dict["�ﱹ����"] = "�ﱹ�Ϻ�����";
				else
					data.dict["�ﱹ����"] = "�ﱹ�Ϻ�����";
			};
		}

		{
			EventMaker e("�ﱹ �Ϻ� ����!", EventPriority::High);
			e->content = "���� ����� �ﱹ�� �Ϻ��ϰ� �����Ͽ����ϴ�!\n\
���� �ô�� �Ѿ�ϴ�!";
			e->CanStart = [&](Gamedata& data) {
				if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
				if (data.dict["�ﱹ����"] == "�ﱹ�Ϻ�����") {
					data.dict["�ô�"] = "���ϱ��ô�";
					data.dict["�÷��̾�"] = "���ϽŶ�";
					return true;
				}
				else
					return false;
			};
		}
	}

	{
		EventMaker e("�ﱹ �Ϻ� ����", EventPriority::High);
		e->content = "�翡 ���� �ѹݵ��� �Ϻθ��� ������ �Ǿ�����\n\
��·�� ����� �Ҹ��ϴ� �ﱹ ������ ���� �̷���ϴ�!\n\
��� �ڿ� / 2\n\
���� �ô�� �Ѿ�ϴ�!";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�") return false;
			if (data.dict["�ﱹ����"] == "�ﱹ�Ϻ�����") {
				data.dict["�ô�"] = "���ϱ��ô�";
				data.dict["�÷��̾�"] = "���ϽŶ�";
				data.player.res.food /= 2;
				data.player.res.human /= 2;
				data.player.res.money /= 2;
				data.player.res.diplo /= 2;
				data.player.res.milli /= 2;
				data.player.res.faith /= 2;
				return true;
			}
			else
				return false;
		};
	}
}
void ���ϱ��ô�(EventManager& evt_mng) {
	{
		EventMaker e("��������", EventPriority::High);
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			data.dict["�÷��̾�"] = "���ϽŶ�";
			return data.dict["�÷��̾�"] == "";
		};
	}

	{
		EventMaker e("�� û��", EventPriority::High);
		e->content = "��ȭ�ο� �����\n\
�� ������ �ͼ� ������ �ǻ��� �����մϴ�\n\
������ �̷� ��ȭ�ο� �ô뿡 ������ ������ ������ �ʽ��ϴ�\n\
�Դٰ� ���ŵ��� �� �ڸ� �����϶�� �ϳ׿�\n\
�� û���� ��� �ұ��?";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["û����"] == "")
				return true;
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "������ ó�����Ѷ�!!");
			s->content = "�� û���� �ٷ� ó����ŵ�ϴ�\n\
�����+\n\
�η�-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.milli += 1;
				data.player.res.human -= 4;
				data.dict["û����"] = "ó��";
			};
		}

		{
			EventSelectItemMaker s(e, "(�����Ѵ�)");
			s->content = "�� û�⿡�� ���� ������ ������\n\
���� �ͱ�￩ ������ �ʽ��ϴ�\n\
�ž�-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.faith -= 3;
				data.dict["û����"] = "����";
			};
		}

		{
			EventSelectItemMaker s(e, "������ ����...");
			s->content = "���Ǹ� ��������\n\
�� û���� ���� �ͱ�￩ ���ϴ�\n\
�����+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.milli += 3;
				data.dict["û����"] = "��û";
			};
		}
	}
	{
		EventMaker e("ó��", EventPriority::High);
		e->content = "1����...\n\
�������� �ֺ� �ΰ��� �а� ������ Ŀ��\n\
�츮 ���ε��� �ٴٷ� ���� �� ���� �Ǿ����ϴ�...";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["û����"] == "ó��") {
				data.player.res.human -= 10000;
				return true;
			}
			else
				return false;
		};
	}

	{
		EventMaker e("����", EventPriority::High);
		e->content = "1����...\n\
�������� �ֺ� �ΰ��� �а� ������ Ŀ������\n\
�� û���� �ܿ�ܿ� ���� �ִٰ� �մϴ�\n\
���� ���� ���� �׷��׿�...\n\
�ž�-\n\
�η�-\n\
��--";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["û����"] == "����") {
				data.player.res.faith -= 3;
				data.player.res.human -= 3;
				data.player.res.money -= 5;
				data.dict["û����"] = "��";
				return true;
			}
			else
				return false;
		};
	}

	{
		EventMaker e("��û", EventPriority::High);
		e->content = "���� ���� ���� ��û�߰�\n\
���´� �������� �ɰ��߽��ϴ�\n\
���� ���� ���� û������ ��ġ�߰�, ��� �� ���� ������ ������ ���������ϴ�.\n\
�Դٰ� ������ ����� �ڿ��� û������ �ػ� ������ �߽����� �Ǿ����ϴ�\n\
�庸���� ���� ���� ���߳׿�\n\
�ž�++\n\
��+\n\
�����++";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["û����"] == "��û") {
				data.dict["û����"] = "��";
				data.player.res.faith += 5;
				data.player.res.money += 3;
				data.player.res.milli += 5;
				return true;
			}
			else
				return false;
		};
	}
	{
		EventMaker e("����", EventPriority::Normal);
		e->content = "������ ���� ���ο� ������ ����ٰ� �մϴ�. �� ������ �̸��� ���ض�� �մϴ�.";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["����"] == "" && evt_mng.RandomInt(0, 2) == 0) {
				data.dict["����"] = "��";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "�ص������̶�� �θ��� �Ǵ°ǰ�?");

			s->Effect = [&](Gamedata& data) {
				data.dict["�ܱ��� ���"] = "";
			};
		}
		{
			EventSelectItemMaker s(e, "���������̶�� �θ��� �Ǵ°ǰ�?");

			s->Effect = [&](Gamedata& data) {
				data.dict["�ܱ��� ���"] = "��";
			};
		}
	}
	{
		EventMaker e("����", EventPriority::Normal);
		e->content = "������ ���� ���ο� ������ ����ٰ� �մϴ�. �� ������ �̸��� ���ض�� �մϴ�.";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["����"] == "" && evt_mng.RandomInt(0, 2) == 0) {
				data.dict["����"] = "��";
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "ȫ�浿�� ���ظ� �Ǳ�����...");

			s->Effect = [&](Gamedata& data) {
				data.dict["�ܱ��� ���"] = "��";
			};
		}
		{
			EventSelectItemMaker s(e, "�������� ���ظ� �Ǳ�����...");

			s->Effect = [&](Gamedata& data) {
				data.dict["�ܱ��� ���"] = "";
			};
		}
	}
	{
		EventMaker e("�ܱ��� ���", EventPriority::Highest);
		e->content = "����� �����ϰԵ� �ܱ��� ��ʸ� �����׽��ϴ�.";
		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "���ϱ��ô�") return false;
			if (data.dict["�ܱ��� ���"] == "��") {
				return true;
			}
			else
				return false;
		};

		{
			EventSelectItemMaker s(e, "�̾�.");

			s->content = "�ܱ�--";

			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo -= 8;
				data.dict["�ܱ��� ���"] = "";
			};
		}
	}

	{
		EventMaker e("�������� �� ����", EventPriority::Low);
		e->content =
			"������ ������ ����� ������ ���մϴ�. �״� ���߿� ���̸� �ŷ��ϱ� ���մϴ�.";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�" && data.dict["�ô�"] != "���ϱ��ô�" && data.dict["�ô�"] != "����ô�" && data.dict["�ô�"] != "�����ô�") return false;
			
			return evt_mng.RandomInt(0, 3) == 0;

		};

		{
			EventSelectItemMaker s(e, "�� �ŷ��� �츮 ��ο��� �̵��� �ɰ��̴�.");
			s->content =
				"�ķ�+\n�ܱ���+\n��+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food += 1;
				data.player.res.diplo += 1;
				data.player.res.money += 1;
			};
		}
	}

	{
		EventMaker e("ȫ��", EventPriority::Normal);
		e->content =
			"���� ��ó�� ��â���뿡�� ū ȫ���� �����ϴ�. �츮�� ������ �ؾ� �� ���?";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�" && data.dict["�ô�"] != "���ϱ��ô�" && data.dict["�ô�"] != "����ô�" && data.dict["�ô�"] != "�����ô�") return false;

			return evt_mng.RandomInt(0, 6) == 0;

		};

		{
			EventSelectItemMaker s(e, "�����븦 ������ �鼺���� �����ʰ� �ķ��� ������ �־��.");
			s->content =
				"�η�-\n�ķ�--\n�ܱ���+\n��-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 1;
				data.player.res.food -= 5;
				data.player.res.diplo += 3;
				data.player.res.money -= 3;
			};
		}
		{
			EventSelectItemMaker s(e, "�Ų��� ���ϽŰ� �и��ϴ�! � ���縦 �غ��ض�!");
			s->content =
				"�η�--\n�ķ�--\n�ž�++++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 7;
				data.player.res.food -= 7;
				data.player.res.faith += 18;
			};
		}
		{
			EventSelectItemMaker s(e, "�鼺���� �׵� ���� ���� ���� ����̳�!");
			s->content =
				"�η�--\n�ķ�-\n�ܱ���-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 5;
				data.player.res.food -= 5;
				data.player.res.diplo -= 2;
			};
		}
	}

	{
		EventMaker e("����", EventPriority::Lowest);
		e->content =
			"�������� �츮�� ����Ѵ�� ������ ������ ���̰� �ֽ��ϴ�. .";

		{
			EventSelectItemMaker s(e, "������ ���ٸ� ������ ���� �ɼ� ����.");
			s->content =
				"�ķ�++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food += 10;
			};
			s->CanVisible = [&](Gamedata& data) {
				return data.dict["�ô�"] != "�ٴ�ô�";
			};
		}
		{
			EventSelectItemMaker s(e, "������ ���ٸ� ������ ���� �ɼ� ����.");
			s->content =
				"��++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.money += 10;
			};
			s->CanVisible = [&](Gamedata& data) {
				return data.dict["�ô�"] == "�ٴ�ô�";
			};
		}
	}
	{
		EventMaker e("ǳ��", EventPriority::Normal);
		e->content =
			"ǳ���Դϴ�. �̶����� ��⺸�� �� ���� �ķ��� ���� �˴ϴ�";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�" && data.dict["�ô�"] != "���ϱ��ô�" && data.dict["�ô�"] != "����ô�" && data.dict["�ô�"] != "�����ô�") return false;

			return evt_mng.RandomInt(0, 3) == 0;

		};
		{
			EventSelectItemMaker s(e, "��� ��â�� �־��!");
			s->content =
				"�ķ�++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food += 10;
			};
		}
		{
			EventSelectItemMaker s(e, "ǳ���� �����ֽ� õ���Ÿ�Բ� �������縦 �����!");
			s->content =
				"�ķ�+\n�ž�+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food += 5;
				data.player.res.faith += 4;
			};
		}
	}
	{
		EventMaker e("����", EventPriority::Low);
		e->content =
			"�����Դϴ�. �鼺���� ���ָ��� �ֽ��ϴ�. �ε� �ں�Ӱ� ��ó�Ͻʽÿ�";

		e->CanStart = [&](Gamedata& data) {
			if (data.dict["�ô�"] != "�ﱹ�ô�" && data.dict["�ô�"] != "���ϱ��ô�" && data.dict["�ô�"] != "����ô�" && data.dict["�ô�"] != "�����ô�") return false;

			return evt_mng.RandomInt(0, 4) == 0;

		};
		{
			EventSelectItemMaker s(e, "��â�� �����!");
			s->content =
				"�ķ�-/�η�-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food -= 3;
				data.player.res.human -= 3;
			};
		}
		{
			EventSelectItemMaker s(e, "�׷���...?");
			s->content =
				"�η�--";
			s->Effect = [&](Gamedata& data) {
				data.player.res.human -= 7;
			};
		}
	}
	{
		EventMaker e("����", EventPriority::High);
		e->content =
			"������ �������Դϴ�. ";

		{
			e->CanStart = [&](Gamedata& data) {
				if (data.dict["�ô�"] != "�ﱹ�ô�" && data.dict["�ô�"] != "���ϱ��ô�" && data.dict["�ô�"] != "����ô�" && data.dict["�ô�"] != "�����ô�") return false;

				return evt_mng.RandomInt(0, 12) == 0;

			};

			EventSelectItemMaker s(e, "�����鸸 �ʴ��϶�.");
			s->content =
				"��-\n�ž�+\n�ܱ���+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.money -= 4;
				data.player.res.faith += 5;
				data.player.res.diplo += 2;
			};
		}
		{
			EventSelectItemMaker s(e, "�ܱ��� ����鵵 �ʴ��϶�.");
			s->content =
				"��--\n�ž�+\n�ܱ���++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.money -= 8;
				data.player.res.faith += 5;
				data.player.res.diplo += 7;
			};
		}
		{
			EventSelectItemMaker s(e, "�����鵵 �ʴ��϶�.");
			s->content =
				"��---\n�ž�++\n�ܱ���++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.money -= 12;
				data.player.res.faith += 9;
				data.player.res.diplo += 7;
			};
		}
		{
			EventSelectItemMaker s(e, "�鼺�鵵 �ʴ��϶�.");
			s->content =
				"��----\n�ž�++++\n�ܱ���++\n�η�+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.money -= 16;
				data.player.res.faith += 18;
				data.player.res.diplo += 7;
				data.player.res.human += 4;
			};
		}
	}

	{
		EventMaker e("ȣ���� ����", EventPriority::Normal);
		e->content =
			"�ֱ� ȣ���� �̷����� ������ �ϰ� �־��ϴ�. �׵��� ������ ������ �ö����� �׵��� �׿� �ɸ��� �Ƿ��� ���մϴ�.";
		e->CanStart = [&](Gamedata& data) {
			return data.dict["�ô�"] != "�ٴ�ô�" && data.dict["�ô�"] != "�����ô�" && evt_mng.RandomInt(0, 9) == 0 && data.dict["ȣ���� �Һ�"] == "";
		};

		{
			EventSelectItemMaker s(e, "ȣ���� ���Ѵٸ� �� ���� �Ƿ��� �־�� �Ѵ�.");
			s->content =
				"�ķ�-\n��-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.food -= 3;
				data.player.res.money -= 3;
				data.dict["���ź��"] = "�����Ǳ�";
				data.dict["�ô�"] = "����ô�";
				//data.dict["ȣ���� �Һ�"] == "��";
			};
		}
		{
			EventSelectItemMaker s(e, "�����ϴ�!");
			s->content =
				"(ȣ���� �Һ���) �̺�Ʈ�� ���۵˴ϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["ȣ���� �Һ�"] = "����";
			};
		}
	}
	{
		EventMaker e("ȣ���� �Һ�", EventPriority::High);
		e->content =
			"ȣ���� �������� ���� �������� ������ ��ġ�� �ʰų� ���� ��ġ�� ������ ������ �Ϻδ� �ݶ��� ����Ű�°� �����ϴ�.";
		e->CanStart = [&](Gamedata& data) {
			return data.dict["�ô�"] != "�ٴ�ô�" && data.dict["�ô�"] != "�����ô�" && data.dict["ȣ���� �Һ�"] == "����";
		};

		{
			EventSelectItemMaker s(e, "�׵��� �׿���.");
			s->content =
				"�����--\n�ܱ���-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.milli -= 6;
				data.player.res.diplo -= 3;
				if (evt_mng.RandomInt(0, 6) == 0 || data.dict["�ô�"] == "���ϱ��ô�")
					data.dict["ȣ���� �Һ�"] == "�ݶ�";
				else
					data.dict["ȣ���� �Һ�"] == "";
			};
		}
		{
			EventSelectItemMaker s(e, "�׵�� ȸ���ϱ����� ���� ȣ���� �ڽĵ�� ȥ���Ѵ�.");
			s->content =
				"�ܱ�-";
			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo -= 2;
				data.dict["ȣ���� �Һ�"] = "��";
				data.dict["���ź��"] = "��������";
				data.dict["�ô�"] = "����ô�";
			};
		}
		{
			EventSelectItemMaker s(e, "�׺�.");
			s->content =
				"�й��մϴ�";
			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo = -1;
				data.player.res.faith = 0;
			};
		}
	}
	{
		EventMaker e("ȣ���� �ݶ�", EventPriority::Normal);
		e->content =
			"ȣ���� �츮���� �ݱ⸦ ��� ���ο� ������ ������� �մϴ�! �׵��� ���� �� �Ѵٸ� �츮�� �й��� �� �Դϴ�.";
		e->CanStart = [&](Gamedata& data) {
			return data.dict["�ô�"] != "�ٴ�ô�" && data.dict["�ô�"] != "�����ô�" && data.dict["ȣ���� �Һ�"] == "�ݶ�";
		};

		{
			EventSelectItemMaker s(e, "�̰� ����� ���� �ſ��ϴ� ���̴�. ������ ��� ������ �ĳ־��!");
			s->content =
				"�����---\n�ܱ���+";
			s->Effect = [&](Gamedata& data) {
				data.player.res.milli -= 11;
				data.player.res.diplo += 3;
				data.dict["ȣ���� �Һ�"] = "��";
				data.dict["���ź��"] = "��������";
				data.dict["�ô�"] = "����ô�";
			};
		}
		{
			EventSelectItemMaker s(e, "�׺�.");
			s->content = "���� ������ ��Ĩ�ϴ�.";

			s->CanVisible = [&](Gamedata& data) {
				return data.dict["�ô�"] == "���ϱ��ô�";
			};

			s->Effect = [&](Gamedata& data) {
				data.dict["����� ź��"] = "��";
			};
		}
		{
			EventSelectItemMaker s(e, "�׺�.");
			s->content =
				"����� ���� ����� �÷��� �մϴ�.";
			s->Effect = [&](Gamedata& data) {
				data.dict["�÷��̾�"] = "���";
			};
			s->CanVisible = [&](Gamedata& data) {
				return data.dict["�ô�"] != "���ϱ��ô�";
			};
		}
	}
	{
		EventMaker e("����ô��� ����", EventPriority::Highest);
		e->content =
			"�Ŷ��� �ô�� ���� ������ ����� �ô밡 ���۵Ǿ����ϴ�! ����� �Ŷ� ���� 2��° ���ϱ��� �Դϴ�!";

		e->CanStart = [&](Gamedata& data) {
			return data.dict["����� ź��"] == "��";
		};


		{
			EventSelectItemMaker s(e, "���Ȳ�� ����! ����");
			s->Effect = [&](Gamedata& data) {
				data.dict["�÷��̾�"] = "���";
				data.dict["�ô�"] = "����ô�";
				data.dict["���ź��"] = "��������";
			};
		}
	}
	{
		EventMaker e("������ ��ȭ", EventPriority::Low);
		e->content =
			"���� ������ �Դ븦 �ϱ� ���ϴ� ������� ����á���ϴ�! �׵��� ���� ��ġ���Ѿ� �մϴ�";

		e->CanStart = [&](Gamedata& data) {
			return evt_mng.RandomInt(0, 3) == 0;
		};


		{
			EventSelectItemMaker s(e, "�� ū ����� �� ū ������ �ǹ��Ѵ�");
			s->content =
				"�η�++\n�����++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.milli += 7;
				data.player.res.human += 6;
			};
		}
	}
	{
		EventMaker e("����� �ܱ���", EventPriority::Low);
		e->content =
			"�츮�� �ܱ����� Ÿ���� ���⸦ �����׽��ϴ�. �ٸ� �������� �츮�� ���� �ü��� �޶������ϴ�.";

		e->CanStart = [&](Gamedata& data) {
			return evt_mng.RandomInt(0, 3) == 0;
		};

		{
			EventSelectItemMaker s(e, "������ �޾ƾ��� ����.");
			s->content =
				"�ܱ���++";
			s->Effect = [&](Gamedata& data) {
				data.player.res.diplo += 8;
			};
		}
	}
}
